# Git & GitHub: Quick & Easy Study Guide

**Author: Aditya | Student ID: 2025UCP1043**

---

### 1. Core Foundations: Version Control Paradigms & Architecture

Using a Version Control System (VCS) is essential when building and collaborating on software projects. Without one, developers frequently resort to disorganized filenames such as `vecadd.py`, `vecadd_final.py`, and `vecadd_final_v2_fixed.py`. Manually managing files this way makes it difficult to determine the canonical state, risks data loss from accidental overwrites, and makes team collaboration chaotic.

A VCS solves these issues by maintaining a cryptographically verifiable ledger of changes: it records who modified which line, tracks why modifications occurred via commit messages, enables instantaneous rollback to known good states, and provides deterministic branch isolation.

#### Version Control Paradigms: Comparative Analysis

| VCS Architecture | Mechanism & Characteristics | Trade-offs & Limitations |
| :--- | :--- | :--- |
| **Local VCS** | Stores commit revisions in a flat local database or RCS file on the user's hard drive. | No built-in collaboration; single point of failure if the disk fails. |
| **Centralized VCS** *(e.g., SVN)* | Single central server houses complete history; clients check out individual snapshots. | Requires constant network access; if the server goes offline, no commits or history inspection can take place. |
| **Distributed VCS** *(e.g., Git)* | Every client clone is a complete mirror of the repository, including branches, history, and metadata. | Fully offline-capable, lightning-fast local operations; every workstation acts as a complete distributed backup. |

#### Git (Local Tool) vs. GitHub (Cloud Platform)

| Git (Local Tool) | GitHub (Cloud Platform) |
| :--- | :--- |
| **Category:** Command-line version control engine. | **Category:** Cloud-hosted repository and collaboration platform. |
| **Runtime Environment:** Runs locally on the workstation. | **Runtime Environment:** Runs online on GitHub cloud servers. |
| **Functionality:** Tracks file diffs, manages the staging area, branches, and merges. | **Functionality:** Hosts remote repositories, handles Pull Requests, code reviews, Issues, and Actions. |
| **Network Requirement:** Completely offline for committing, branching, and logs. | **Network Requirement:** Requires an active internet connection to push, pull, and review. |

#### The Three Local Areas & The Remote Flow

Git organizes files across three internal state zones before syncing with remotes:

```
+-----------------------------------------------------------------------------------+
|                               LOCAL WORKSTATION                                   |
|                                                                                   |
|  +--------------------+     git add      +--------------------+   git commit      |
|  | Working Directory  | -------------->  |   Staging Area     | --------------+   |
|  | (Local Sandbox)    |                  |  (Index / Cache)   |               |   |
|  +--------------------+                  +--------------------+               v   |
|            ^                                  ^                       +---------+ |
|            |                                  |                       | Local   | |
|            |                                  |                       | Repo    | |
|            |                                  |                       | (.git)  | |
|            |                                  |                       +---------+ |
+------------|----------------------------------|----------------------------|------+
             |                                  |                            |
             |                                  | git fetch                  | git push
             |                                  +-----------------------+    |
             |                                                          |    |
             |                            git pull                      |    v
             +-------------------------------------------------- [ Remote Repository ]
                                                                   (GitHub Server)
```

- **Working Directory:** The active file tree on disk where code files (such as `vecadd.py` or `readme.txt`) are authored.
- **Staging Area (Index):** A binary caching index where specific file modifications are assembled via `git add` prior to finalizing a commit.
- **Local Repository (`.git`):** The internal object database storing the complete directed acyclic graph (DAG) of commit objects, trees, blobs, and references (`HEAD`).
- **Remote Repository:** The remote Git mirror hosted on GitHub used for collaboration, code reviews, and remote backups.

---

### 2. Local Repository Operations & Daily Workflow

A clean repository history relies on atomic commits—meaning each commit represents a single logical unit of work accompanied by a concise, imperative commit message.

#### Global Setup & Initial Configuration

```bash
# Verify Git installation and version
git --version

# Set author metadata attached to future commits
git config --global user.name "Aditya"
git config --global user.email "2025ucp1043@mnit.ac.in"

# Verify global configuration parameters
git config --global --list
```

#### Step-by-Step Single-Branch Development Workflow

1. **Initialize Workspace:**
   ```bash
   mkdir lab_project && cd lab_project
   git init
   ```
   *Note: `git init` creates the hidden `.git/` folder containing the object database and `HEAD` pointer.*

2. **Staging Changes (`git add`):**
   - Stage a specific file: `git add vecadd.py`
   - Stage all tracked and untracked modifications: `git add .`
   - Stage by wildcard pattern: `git add *.py`

3. **Status Queries & Diff Analysis:**
   - `git status`: Identifies untracked, modified, and staged files.
   - `git diff`: Shows differences between the working tree and the staging area.
   - `git diff --staged`: Compares staged changes against the latest commit (`HEAD`).
   - `git diff HEAD`: Shows all changes (staged and unstaged) relative to `HEAD`.

4. **Committing Changes:** Follow **Conventional Commits** (`<type>(<scope>): <description>`):
   ```bash
   # Conventional feature commit
   git commit -m "feat(vecadd): implement element-wise vector addition"

   # Conventional bug fix commit
   git commit -m "fix(vecadd): handle mismatched vector length exception"
   ```

#### History Inspection, File Manipulation & Rollback Operations

- **Viewing Commit Logs:**
  - `git log`: Full verbose commit history.
  - `git log --oneline`: Compact single-line summary with short commit hashes.
  - `git log -n 5 --stat`: Shows commit messages alongside modified file statistics for the last 5 commits.

- **File Renaming and Deletion:**
  - `git mv old_name.py vecadd.py`: Renames the file and stages the operation in one step.
  - `git rm readme.txt`: Deletes the file from disk and stages the deletion.

- **Excluding Files with `.gitignore`:** Create a `.gitignore` file at the repository root to omit generated artifacts, caches, and secrets:
  ```gitignore
  # Python bytecode & cache
  __pycache__/
  *.pyc

  # Build & temporary logs
  *.log
  dist/
  build/

  # Local environment variables & secrets
  .env
  ```

#### State Restoration Mechanics

```
 Working Directory                 Staging Area (Index)              Local Repository History
  +--------------+                 +------------------+                 +-------------------+
  | Modified     |                 | Staged           |                 | Committed         |
  | Content      |                 | Content          |                 | Snapshots         |
  +--------------+                 +------------------+                 +-------------------+
         ^                                  |                                     |
         |--- git restore <file> -----------|                                     |
         |    (Discards local edits)        |                                     |
         |                                  |                                     |
         |<-- git restore --staged <file> --+                                     |
         |    (Unstages; preserves edits)                                         |
         |                                                                        |
         |<--- git checkout <commit-hash> ----------------------------------------|
         |     (Detached HEAD inspection; switch/checkout main to exit)           |
         |                                                                        |
         |<--- git revert <commit-hash> ------------------------------------------|
               (Applies inverse patch as NEW commit; maintains linear history)
```

1. **Unstaging a File:** `git restore --staged <file>` moves changes from the staging index back to unstaged working files.
2. **Discarding Local Edits:** `git restore <file>` resets the file to the last committed version. *(Caution: Uncommitted modifications are unrecoverable!)*
3. **Detached HEAD Inspection:** `git checkout <commit-hash>` moves `HEAD` directly to a past snapshot for read-only inspection. Return to the branch tip via `git switch main`.
4. **Reverting Commits Safely:** `git revert <commit-hash>` applies an exact inverse patch as a brand-new commit, preserving collaborative branch history.

---

### 3. Branching, Merging, and Conflict Resolution

In Git, a branch is merely a lightweight, movable 41-byte pointer to a commit hash. `HEAD` points to the active branch reference.

#### Branch Management Lifecycle

1. **Creating & Switching Branches:**
   ```bash
   # List existing branches
   git branch

   # Create a new branch named 'feature-opt'
   git branch feature-opt

   # Rename branch to 'parallel'
   git branch -m feature-opt parallel

   # Switch to the 'parallel' branch
   git switch parallel       # Equivalent: git checkout parallel

   # Shortcut: Create and switch in a single step
   git switch -c parallel
   ```

2. **Divergent History Visualization:**
   Inspect branch splitting and commits across all references:
   ```bash
   git log --oneline --all --graph
   ```

#### Merging & Conflict Resolution

- **3-Way Merge (`git merge <branch>`):** Creates a dedicated merge commit joining divergent branch tips, preserving full historical topology.
- **Fast-Forward Merge:** Moves the branch pointer forward without a merge commit when no divergent commits exist on the target branch.
- **Rebase (`git rebase main`):** Re-applies local commits linearly on top of `main`. *(Avoid rebasing public/shared branches).*

#### Resolving Merge Conflicts Step-by-Step

A conflict occurs when two branches alter the exact same line in contradictory ways:

```
<<<<<<< HEAD
print("Result:", standard_vector_add(vec_a, vec_b))
=======
print("Result:", parallel_vector_add(vec_a, vec_b))
>>>>>>> parallel
```

1. **Identify Conflicts:** Run `git status` to locate unmerged paths.
2. **Resolve Manually:** Open the conflicting file in your editor, pick the correct implementation, and delete conflict markers (`<<<<<<<`, `=======`, `>>>>>>>`).
3. **Stage the Fix:** `git add vecadd.py` marks the conflict as resolved.
4. **Finalize Merge:** Complete the operation with `git commit -m "fix(vecadd): resolve merge conflict between standard and parallel additions"`.
5. **Delete Branch Pointer:** `git branch -d parallel` cleans up merged branch references.

#### Stashing Uncommitted Work

To switch branches immediately without committing half-finished code:

```bash
# Push working directory modifications onto the stash stack
git stash

# Perform urgent work on main
git switch main
# ... complete fix & commit ...

# Return to feature branch and restore stashed work
git switch parallel
git stash pop
```

---

### 4. Remote Collaboration & GitHub Platform Workflows

#### Connecting and Syncing with Remotes

```bash
# Link local repository to a remote repository named 'origin'
git remote add origin https://github.com/USERNAME/tw_project.git

# Verify bound fetch and push remote URLs
git remote -v

# Rename local active branch to main and push upstream
git branch -M main
git push -u origin main
```

- **`git fetch origin`**: Downloads remote commits, branches, and tags without altering your local working files.
- **`git pull`**: Fetches updates and automatically performs a merge into your active branch (`git pull = git fetch + git merge`).
- **`git clone <url>`**: Clones a complete remote repository, checking out the default branch and binding `origin` automatically.

#### Forking vs. Cloning

| Dimension | Forking | Cloning |
| :--- | :--- | :--- |
| **Execution Context** | Server-side action executed on GitHub. | Local CLI command executed in the terminal. |
| **Architectural Output** | Creates an independent remote copy under your GitHub account. | Downloads the remote repository onto your local workstation. |
| **Primary Workflow Purpose** | Enables external contributors to open Pull Requests without direct write access. | Sets up a local development workspace to author, test, and commit code. |

#### Pull Requests & Release Tagging

1. **Feature Branch Workflow:**
   - Create local feature branch: `git switch -c feat-optimization`
   - Author, stage, and commit changes.
   - Push branch upstream: `git push -u origin feat-optimization`
   - Open a **Pull Request (PR)** on GitHub targeting the upstream `main` branch.
   - Complete peer code reviews, CI test runs, and merge.
   - Sync local main: `git switch main && git pull origin main`

2. **Milestone Tagging:**
   ```bash
   # Create an annotated release tag
   git tag -a v1.0.0 -m "Release Version 1.0.0 - Production Baseline"

   # Push tag to remote GitHub repository
   git push origin v1.0.0
   ```

3. **Security Caution**: Never commit passwords, tokens, or credentials. Once committed, adding an item to `.gitignore` does not remove it from historical commit trees. Exposed keys must be immediately revoked and purged using tools like `git-filter-repo`.

---

### 5. Quick Command Cheat Sheet

| Category | Command Syntax | Description |
| :--- | :--- | :--- |
| **Identity Setup** | `git config --global user.name "Aditya"` | Sets author name globally. |
| **Email Setup** | `git config --global user.email "email@domain"` | Sets author email globally. |
| **Init** | `git init` | Initializes a new Git repository. |
| **Status** | `git status` | Displays working tree and staging state. |
| **Staging** | `git add <file>` / `git add .` | Stages modifications for commit. |
| **Commit** | `git commit -m "Message"` | Saves staged changes into history. |
| **Diff** | `git diff` / `git diff --staged` | Displays working vs staged modifications. |
| **Log** | `git log --oneline --graph --all` | Displays branch graph and commit log. |
| **Unstage** | `git restore --staged <file>` | Removes file from staging area. |
| **Discard** | `git restore <file>` | Discards local uncommitted edits. |
| **Safe Undo** | `git revert <commit-hash>` | Reverses a commit via a new commit. |
| **Branching** | `git branch <name>` | Creates a new branch reference. |
| **Switching** | `git switch <name>` | Switches active branch context. |
| **Merging** | `git merge <name>` | Merges specified branch into active branch. |
| **Branch Deletion**| `git branch -d <name>` | Deletes merged branch pointer. |
| **Stash** | `git stash` / `git stash pop` | Stashes and restores uncommitted edits. |
| **Remote Link** | `git remote add origin <url>` | Links repository to a remote endpoint. |
| **Push** | `git push -u origin main` | Pushes local branch commits upstream. |
| **Pull** | `git pull` | Fetches and integrates remote updates. |
| **Tagging** | `git tag -a v1.0 -m "Release"` | Creates an annotated release milestone. |

