# Technical Writing

**Author:** Aditya  
**Student ID:** 2025UCP1043  
**Institution:** Malaviya National Institute of Technology (MNIT) Jaipur  
**Department:** Computer Science and Engineering  
**Course:** Technical Writing Lab (TW Lab)

---

## 📌 Repository Overview

This repository contains academic coursework, practical assignments, engineering implementations, and reference guides developed for the Technical Writing & Tools Laboratory. The workspace is structured into three primary modules:

1. [**`Latex/`**](#-1-latex-module) — Source documents, compiled PDFs, and comprehensive guides for academic typesetting in $\LaTeX{}$ (equations, tables, figures, documents, and Beamer presentations).
2. [**`Git and Github/`**](#-2-git--github-module) — Version control workflows, branch isolation, conflict resolution, and Python automation.
3. [**`Doxygen/`**](#-3-doxygen-module) — Modular C++ source code with Doxygen documentation, AST extraction, configuration files, and generated HTML/$\LaTeX{}$ API manuals.

---

## 📂 Repository Structure

```
TW_/
├── README.md                               # Central project documentation
│
├── Latex/                                  # LaTeX typesetting module
│   ├── hello_world.tex / .pdf              # Basic minimal document structure
│   ├── First_Latex.tex / .pdf              # Numbered lists, equations & BibTeX citations
│   ├── Math_Equations.tex / .pdf           # Advanced mathematical typesetting & calculus
│   ├── Tables_and_Matrices.tex / .pdf      # Complex tables (booktabs, colortbl) & block matrices
│   ├── Lists_Colors_Figures.tex / .pdf     # Image manipulation, minipages, & custom RGB colors
│   ├── Document_Structure.tex / .pdf       # Font styling, saveboxes, parboxes, & makeidx index
│   ├── Report.tex / .pdf                   # Formal report with fancyhdr and sectsty headings
│   ├── beamer.tex / .pdf                   # Slide deck presentation using Beamer (Madrid theme)
│   ├── mnit_logo.png                       # Institutional emblem graphic asset
│   ├── mnit_building.jpg                   # Campus architectural graphic asset
│   ├── physics.bib                         # BibTeX citation database
│   ├── LaTeX_Essentials_Guide.md           # Comprehensive LaTeX reference manual
│   └── Beamer_Quick_Reference.md           # Complete LaTeX Beamer presentation guide
│
├── Git and Github/                         # Version control & script module
│   ├── vecadd.py                           # Vector arithmetic Python script
│   ├── Git basics.pdf                      # Lab reference on Git foundations
│   └── Git_and_GitHub.md                   # Comprehensive Git & GitHub study guide
│
└── Doxygen/                                # Automated code documentation module
    ├── Calculation_Engine.h                # Mathematical calculation engine interface
    ├── Logger.h                            # Leveled console logging utility
    ├── main.cpp                            # Application driver & @mainpage landing portal
    ├── Doxyfile                            # Fully tuned Doxygen build configuration
    ├── Doxygen_and_Google_Docs.md          # Technical documentation & tools study guide
    ├── html/                               # Generated interactive HTML documentation
    │   └── index.html                      # Web documentation entry point
    └── latex/                              # Generated LaTeX reference documentation
        └── refman.tex                      # Main PDF compilation target
```

---

## 📑 Module Details

### 📝 1. LaTeX Module

The `Latex/` directory hosts progressive lab assignments covering the entire $\LaTeX{}$ document preparation workflow:

| File Name | Topic & Focus Area | Key Packages Used |
| :--- | :--- | :--- |
| `hello_world.tex` | Minimal syntax & structure | Standard `article` class |
| `First_Latex.tex` | Sections, numbered lists, math, and external BibTeX references | `amsmath`, `natbib` |
| `Math_Equations.tex` | Advanced calculus, fractions, roots, multi-line equations, and matrices | `amsmath`, `amssymb` |
| `Tables_and_Matrices.tex` | Multicolumn, multirow, cell shading (`colortbl`), `booktabs`, nested tables | `booktabs`, `multirow`, `xcolor`, `colortbl` |
| `Lists_Colors_Figures.tex` | Image rotation, cropping, side-by-side `minipage` figures, custom RGB colors | `graphicx`, `xcolor`, `caption` |
| `Document_Structure.tex` | Font configuration, `parbox`, `savebox`, section numbering, and `makeidx` | `geometry`, `pagecolor`, `makeidx`, `xcolor` |
| `Report.tex` | Multi-chapter reports, title pages, custom headers/footers, and section fonts | `report`, `geometry`, `fancyhdr`, `sectsty` |
| `beamer.tex` | Professional slide presentations with Madrid theme | `beamer` |

#### Compilation Commands

```bash
# Standard document compilation
pdflatex Document_Structure.tex
makeindex Document_Structure.idx
pdflatex Document_Structure.tex

# Documents with bibliographies
pdflatex First_Latex.tex
bibtex First_Latex
pdflatex First_Latex.tex
pdflatex First_Latex.tex
```

---

### 🐙 2. Git & GitHub Module

The `Git and Github/` directory focuses on modern version control practices and reproducible scripting:

- **`vecadd.py`**: Python script implementing vector operations, used as a testbed for Git branching, merges, and merge-conflict resolution.
- **`Git_and_GitHub.md`**: In-depth study guide covering:
  - Architecture: Working Directory $\rightarrow$ Staging Area $\rightarrow$ Local Repository $\rightarrow$ Remote Repository.
  - Daily Workflows: Staging (`git add`), conventional commit messages, diff queries, and log inspections.
  - Safe State Rollbacks: `git restore`, `git restore --staged`, detached `HEAD`, and `git revert`.
  - Branching & Conflict Resolution: Fast-forward vs. 3-way merges, conflict marker resolution, and `git stash`.
  - Remote Workflows: Remotes, upstream tracking, forking vs. cloning, Pull Requests, and release tagging.

---

### ⚙️ 3. Doxygen Module

The `Doxygen/` directory contains an object-oriented C++ codebase demonstrating automated source code extraction and API manual generation:

- **`Calculation_Engine.h`**: Encapsulates arithmetic exponentiation (`power_calculation`) with edge-case zero-division checks and embedded $\LaTeX{}$ mathematical formulas ($\text{base}^{\text{exponent}}$).
- **`Logger.h`**: Header-only utility providing severity-based console logging (`LogLevel::INFO`, `WARNING`, `ERROR`).
- **`main.cpp`**: Entry point tying modules together and hosting the central `@mainpage` project overview.
- **`Doxyfile`**: Configuration file customized for modern documentation extraction:
  - `EXTRACT_ALL = YES` & `EXTRACT_PRIVATE = YES`: Complete API and private member extraction.
  - `SOURCE_BROWSER = YES`: Full interactive, line-numbered source code view.
  - `USE_MATHJAX = YES`: Client-side browser rendering of $\LaTeX{}$ mathematical expressions.
  - `HAVE_DOT = YES`: Graphical class hierarchies and function call graphs (requires Graphviz).

#### Generating Documentation

```bash
# Navigate to Doxygen directory
cd Doxygen

# Execute Doxygen build
doxygen Doxyfile

# View web documentation
# Open html/index.html in any browser

# Compile LaTeX reference manual to PDF (optional)
cd latex
pdflatex refman.tex
```

---

## 🛠️ Required Toolchain & Setup

To compile and execute the components in this repository, the following tools are recommended:

| Tool | Recommended Distribution | Verification Command |
| :--- | :--- | :--- |
| **LaTeX Engine** | [MiKTeX](https://miktex.org/) (Windows) or [TeX Live](https://tug.org/texlive/) (Linux/macOS) | `pdflatex --version` |
| **Version Control** | [Git](https://git-scm.com/) | `git --version` |
| **Doc Generator** | [Doxygen](https://www.doxygen.nl/) (v1.9.0+) | `doxygen --version` |
| **Diagram Tool** | [Graphviz](https://graphviz.org/) | `dot -V` |
| **C++ Compiler** | GCC (`g++`) or Clang (C++17 or newer) | `g++ --version` |
| **Python Runtime**| Python 3.8+ | `python --version` |

---

## 👤 Author Information

- **Name:** Aditya
- **Student ID:** 2025UCP1043
- **Institution:** Malaviya National Institute of Technology (MNIT), Jaipur
- **Department:** Department of Computer Science and Engineering

