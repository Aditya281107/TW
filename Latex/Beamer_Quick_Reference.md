**Author:** Aditya (ID: 2025UCP1043)

# LaTeX Beamer Quick Reference

A practical, comprehensive reference guide for creating professional presentations using the \LaTeX{} `beamer` class.

---

## 1. Core Concepts & Presentation Structure

Beamer is a powerful \LaTeX{} class designed for typesetting presentation slides. Unlike conventional documents that arrange text across flowing pages, Beamer structures content into discrete **frames**. Compiling a Beamer `.tex` file produces a standard PDF with vector typography, embedded mathematical typesetting, hyperlinks, and cross-references.

### Minimal Slide Template

Every presentation requires `\documentclass{beamer}` and encloses slide content within the `frame` environment:

```latex
\documentclass{beamer}

% Preamble metadata
\title{Introduction to Technical Presentations}
\subtitle{Modern Typesetting with LaTeX Beamer}
\author{Aditya}
\institute{Malaviya National Institute of Technology Jaipur}
\date{\today}

\begin{document}

% Title slide
\begin{frame}
  \titlepage
\end{frame}

% Content slide
\begin{frame}{Welcome}
  \framesubtitle{Getting Started}
  Welcome to your first Beamer presentation!
\end{frame}

\end{document}
```

### Essential Class Options

Options can be supplied directly in `\documentclass[...]` to configure slide geometry, base font size, and compilation behavior:

| Option | Description & Use Case | Syntax Example |
| :--- | :--- | :--- |
| `aspectratio=169` | Formats slides in modern 16:9 widescreen format (ideal for monitors and projectors). | `\documentclass[aspectratio=169]{beamer}` |
| `aspectratio=1610` | Formats slides in 16:10 widescreen aspect ratio. | `\documentclass[aspectratio=1610]{beamer}` |
| `aspectratio=43` | Formats slides in traditional 4:3 standard format (default). | `\documentclass[aspectratio=43]{beamer}` |
| `handout` | Collapses all overlay transitions into one static page per frame for printing or distribution. | `\documentclass[handout]{beamer}` |
| `10pt`, `11pt`, `12pt` | Specifies the base font size for standard body text. | `\documentclass[11pt]{beamer}` |
| `draft` | Speeds up compilation by skipping graphics rendering and drawing placeholder boxes. | `\documentclass[draft]{beamer}` |

---

## 2. Frames, Title Info & Content Blocks

### Creating Frames with Titles & Subtitles

Slide titles and subtitles can be defined either as positional parameters to `\begin{frame}` or through dedicated macros:

```latex
% Method A: Direct arguments
\begin{frame}{Primary Topic Title}{Detailed Subtitle}
  Slide body content goes here.
\end{frame}

% Method B: Command syntax inside frame body
\begin{frame}
  \frametitle{Primary Topic Title}
  \framesubtitle{Detailed Subtitle}
  Slide body content goes here.
\end{frame}
```

### Configuring the Title Slide

Metadata commands in the preamble accept an optional bracketed short form `[...]` that themes display in headers or footers:

```latex
\title[Tech Presentations]{Technical Document Presentation in LaTeX}
\subtitle{Structure and Design Principles}
\author[Aditya]{Aditya (ID: 2025UCP1043)}
\institute[MNIT Jaipur]{Department of Computer Science and Engineering\\MNIT Jaipur}
\date[Nov 2026]{\today}
\titlegraphic{\includegraphics[width=1.5cm]{mnit_logo.png}}

\begin{document}
\begin{frame}
  \titlepage
\end{frame}
\end{document}
```

### Outlines & Section Management

`\section{...}` and `\subsection{...}` commands are placed **outside** of frames. They populate navigation bars, header breadcrumbs, and table of contents:

```latex
\begin{frame}{Table of Contents}
  \tableofcontents[currentsection] % Highlights active section
\end{frame}

\section{System Architecture}
\begin{frame}{Overview of Architecture}
  Discussion of core modular subsystems...
\end{frame}
```

### Content Blocks & Callouts

Beamer includes built-in block environments for organizing content into colored emphasis boxes:

```latex
\begin{frame}{Key Results and Analysis}
  Highlight key findings using \alert{alert text}.

  % Standard block
  \begin{block}{Core Finding}
    Optimized memory access improves overall throughput.
  \end{block}

  % Alert / Warning block
  \begin{alertblock}{Caveat}
    High network latency will degrade parallel scaling.
  \end{alertblock}

  % Example block (often rendered in green)
  \begin{exampleblock}{Sample Configuration}
    Set worker thread count equal to available CPU cores.
  \end{exampleblock}
\end{frame}
```

#### Predefined Mathematical Environments

Beamer provides pre-styled theorem and definition environments:

```latex
\begin{frame}{Theoretical Formulation}
  \begin{definition}[Efficiency Metric]
    Efficiency is defined as useful work divided by total resource consumption.
  \end{definition}

  \begin{theorem}[Convergence Bound]
    For all $\epsilon > 0$, the iterative error satisfies $\|e_k\| \le \mathcal{O}(k^{-2})$.
  \end{theorem}
\end{frame}
```

---

## 3. Step-by-Step Reveals & Overlays

Overlays control the progressive reveal of points across consecutive slides within a single frame.

### Simple Pausing with `\pause`

The simplest way to create sequential transitions is the `\pause` command:

```latex
\begin{frame}{Step-by-Step Analysis}
  \begin{itemize}
    \item Point 1: System requirements verified.
    \pause
    \item Point 2: Benchmark suite initialized.
    \pause
    \item Point 3: Execution completed successfully.
  \end{itemize}
\end{frame}
```

### Overlay Specifications (`<spec>`)

Fine-grained control over visibility is achieved by appending `<spec>` to commands and list items:

| Specification | Display Rule | Example Usage |
| :--- | :--- | :--- |
| `<1>` | Visible only on slide 1. | `\item<1> Appears on first slide only` |
| `<2->` | Appears from slide 2 through the end of the frame. | `\item<2-> Persists from slide 2 onward` |
| `<-2>` | Visible from slide 1 up to slide 2. | `\item<-2> Disappears after slide 2` |
| `<2-4>` | Visible on slides 2, 3, and 4. | `\item<2-4> Active on slides 2 through 4` |
| `<1,3>` | Visible on slides 1 and 3, omitted on slide 2. | `\item<1,3> Visible on 1 and 3` |

### Visibility Directives: `\onslide` vs `\uncover` vs `\only`

- **`\onslide<spec>{...}`**: Generic overlay modifier; controls visibility for following content.
- **`\uncover<spec>{...}`**: Hides text on inactive slides while **reserving its physical space** in the document flow.
- **`\only<spec>{...}`**: Inserts text **strictly** on the specified slides without reserving layout space when absent (ideal for swapping images or formulas in place).

```latex
\begin{frame}{Comparison of Visibility Directives}
  \uncover<1>{Element 1: Always occupies physical layout space.}
  
  \uncover<2>{Element 2: Appears on sub-slide 2 without shifting layout.}

  \only<3>{Element 3: Replaces elements in place on sub-slide 3.}
\end{frame}
```

### Covering Style (Transparency & Dimming)

To render inactive items as dim, semi-transparent text instead of completely hiding them:

```latex
\setbeamercovered{transparent} % Renders covered items semi-transparent
% Or use dynamic transparency for progressive reveals:
\setbeamercovered{dynamic}
```

---

## 4. Multi-Column Layouts

Organizing slides into side-by-side columns (e.g., text beside a diagram or code) is achieved via the `columns` environment:

```latex
\begin{frame}{Side-by-Side Comparison}
  \begin{columns}[T] % [T] aligns columns at the top
    \begin{column}{0.48\textwidth}
      \textbf{Textual Summary}
      \begin{itemize}
        \item Modular architecture
        \item Clean separation of concerns
        \item Comprehensive unit test coverage
      \end{itemize}
    \end{column}
    
    \begin{column}{0.48\textwidth}
      \centering
      \includegraphics[width=\linewidth]{mnit_building.jpg}
      \captionof{figure}{Campus Building Overview}
    \end{column}
  \end{columns}
\end{frame}
```

---

## 5. Themes, Colors & Fonts

Beamer provides a modular theme architecture separating structural layouts from color palettes.

### Presentation Layout Themes & Color Themes

```latex
% Structural presentation themes
\usetheme{Madrid}         % Clean corporate theme with header/footer bars
% Other popular themes: Berlin, CambridgeUS, Frankfurt, Copenhagen, Singapore

% Color schemes
\usecolortheme{default}   % Classic navy blue palette
% Other color themes: dolphin, seahorse, beaver (red), wolverine (yellow/blue)
```

### Typography and Custom Colors

```latex
% Use serif fonts for presentations:
\usefonttheme{serif}

% Use professional fonts for clean math symbols:
\usefonttheme{professionalfonts}

% Customizing individual theme elements:
\setbeamercolor{frametitle}{fg=white, bg=blue!80!black}
\setbeamercolor{block title}{fg=white, bg=blue!70!black}
\setbeamerfont{title}{size=\huge, series=\bfseries}
```

---

## 6. Verbatim Code Blocks, Handouts & Export Modes

### Code Listings and Fragile Frames

When embedding verbatim environments (such as `verbatim`, `lstlisting`, or `minted`), always add the **`[fragile]`** option to `\begin{frame}`:

```latex
\begin{frame}[fragile]{Source Code Implementation}
  Below is a sample C++ logging call:
\begin{verbatim}
#include "Logger.h"

int main() {
    Logger logger("[App]");
    logger.log(LogLevel::INFO, "Application started.");
    return 0;
}
\end{verbatim}
\end{frame}
```

### Generating Printable Handouts

To condense animation sequences and print slides (e.g., 2, 4, or 6 slides per page) without multi-click clutter:

```latex
\documentclass[handout]{beamer}
\usepackage{pgfpages}
\pgfpagesuselayout{2 on 1}[a4paper, border shrink=5mm]
```

### Mode-Specific Slide Filtering

Control which frames appear during live presentations versus printed handouts:

- `<beamer:0>`: Excludes slide from live presentation, includes in handout.
- `<handout:0>`: Includes slide in live presentation, omits from handout (e.g. interactive quizzes, animations).

```latex
\begin{frame}<handout:0>{Live Interactive Demo}
  This slide appears during the live session but is excluded from printed handouts.
\end{frame}
```

---

## 7. Quick Command Cheat Sheet

| Category | Syntax | Functional Description |
| :--- | :--- | :--- |
| **Document Class** | `\documentclass[aspectratio=169]{beamer}` | Initializes 16:9 widescreen presentation. |
| **Frame Container** | `\begin{frame}{Title}{Subtitle} ... \end{frame}` | Standard slide environment. |
| **Title Page** | `\titlepage` | Renders title, author, date, and institution. |
| **Outlines** | `\tableofcontents` | Auto-generates indexed slide outline. |
| **Emphasis** | `\alert{keyword}` | Highlights text in theme alert color (usually red). |
| **Standard Block** | `\begin{block}{Title} ... \end{block}` | Renders framed content box with header. |
| **Alert Block** | `\begin{alertblock}{Title} ... \end{alertblock}` | Renders warning/alert styled box. |
| **Example Block** | `\begin{exampleblock}{Title} ... \end{exampleblock}` | Renders example styled box (green theme). |
| **Columns** | `\begin{columns}[T] \begin{column}{0.5\textwidth}` | Organizes layout into multi-column format. |
| **Step Reveal** | `\pause` | Pauses presentation flow until next click. |
| **Overlay Range** | `\item<2->` or `\uncover<2-3>` | Specifies slide visibility interval. |
| **Code Frames** | `\begin{frame}[fragile]` | Mandatory parameter for frames containing code. |
| **Covered Style** | `\setbeamercovered{transparent}` | Renders hidden overlay items semi-transparent. |
| **Handout Mode** | `\documentclass[handout]{beamer}` | Flattens animations into single static pages. |

