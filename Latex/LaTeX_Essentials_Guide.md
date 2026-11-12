# Quick Review Guide: LaTeX Essentials for Assignments & Projects

# Author: ADITYA (ID: 2025UCP1043)

---

### 1. Getting Started with LaTeX

LaTeX is a high-precision document preparation and typesetting system designed to produce clean, professional documents. Instead of forcing authors into manual visual alignment, LaTeX decouples content creation from presentation logic: semantic markup handles structural hierarchy, document geometry, and advanced mathematical typesetting.

#### 1.1 Installation Quick-Setup

Compiling LaTeX source files locally requires a TeX distribution (such as TeX Live, MiKTeX, or MacTeX). Below is an overview across standard operating systems:

| Operating System | Distribution | Package Manager / Installation Command | Verification Command |
| :--- | :--- | :--- | :--- |
| **Linux (Ubuntu/Debian)** | TeX Live | `sudo apt update && sudo apt install texlive-full` | `pdflatex --version` |
| **macOS** | MacTeX | `brew install --cask mactex` | `xelatex --version` |
| **Windows** | MiKTeX / TeX Live | Official Setup Installer (`https://miktex.org/download`) | `pdflatex --version` |

*Note: Verify that the installation bin directory is added to your system `PATH` environment variable so compiler CLI utilities run smoothly from any terminal.*

#### 1.2 LaTeX Compilation Engines

Different compilation engines process LaTeX documents depending on package dependencies, font requirements, and scripting needs:

- **`pdflatex`**: The primary direct-to-PDF compiler. It converts standard `.tex` source code directly into PDF documents, supporting standard packages and EPS/PNG/JPEG graphics.
- **`xelatex`**: An engine with native Unicode input support that can directly access system OpenType and TrueType fonts via the `fontspec` package.
- **`lualatex`**: An advanced compiler embedding a Lua runtime scripting engine alongside native modern Unicode font typesetting.
- **`bibtex`**: An external citation processor that reads bibliographical databases (`.bib`) and generates formatted reference lists (`.bbl`).
- **`makeindex`**: An index generation processor that compiles raw index markers (`.idx`) into formatted alphabetical index entries (`.ind`).

Because cross-references, equation links, page counters, and bibliographies rely on auxiliary cache files, a multi-pass compilation sequence is necessary:

```bash
# Multi-pass compilation sequence for complete cross-reference and index resolution
pdflatex report.tex
bibtex report
makeindex report.idx
pdflatex report.tex
pdflatex report.tex
```

1. **First Pass (`pdflatex report.tex`)**: Emits primary auxiliary metadata (`.aux`), citation reference targets, and raw index entries (`.idx`).
2. **Citation Pass (`bibtex report`)**: Parses citation keys against the `.bib` file to produce the formatted bibliography file (`.bbl`).
3. **Indexing Pass (`makeindex report.idx`)**: Sorts, groups, and formats raw index entries into the alphabetized `.ind` file.
4. **Second Compilation Pass (`pdflatex report.tex`)**: Incorporates bibliographies and indexes while updating page numbers and document counters.
5. **Final Pass (`pdflatex report.tex`)**: Resolves remaining cross-reference targets, labels (`\ref`), and table of contents entries without warnings.

---

### 2. Basic Document Structure & Formatting

Every LaTeX document comprises a **preamble** (everything preceding `\begin{document}`) and the **document body**.

#### 2.1 Document Classes

Declare the root document type using `\documentclass[options]{class}` as line 1:

- `article`: Suitable for lab assignments, academic papers, and technical reports.
- `report`: Ideal for semester projects, laboratory manuals, and theses requiring `\chapter` divisions.
- `book`: Used for full-length technical volumes with front matter, main matter, and back matter.
- `beamer`: Specialized class for rendering conference presentations and classroom lecture slides.
- `letter`: Template for formal business correspondence.
- `exam`: Designed for crafting question papers and quizzes with grading points and solution blocks.

Configure margins, paper sizing, and orientation with the `geometry` package:

```latex
\documentclass[12pt, a4paper]{report}
\usepackage{geometry}
\geometry{a4paper, margin=1in, top=2.5cm, bottom=2.5cm}
```

#### 2.2 Essential Packages & Visual Customizations

Enhance documents with specialized packages loaded in the preamble:

- **`fancyhdr`**: Provides customizable headers and footers:
```latex
\usepackage{fancyhdr}
\pagestyle{fancy}
\fancyhf{} % Clear existing headers and footers
\fancyhead[L]{\textbf{Technical Writing Lab}}
\fancyhead[C]{Assignment Review}
\fancyhead[R]{\today}
\fancyfoot[C]{Page \thepage}
```
*Standard header styles include `empty` (no headers/footers), `plain` (centered footer page numbers), and `fancy`.*

- **`sectsty`**: Modifies the appearance of headings across levels:
```latex
\usepackage{sectsty}
\chapterfont{\color{blue}\bfseries\huge}
\sectionfont{\color{teal}\bfseries\Large}
\subsectionfont{\color{darkgray}\itshape\large}
```

- **`fontspec`**: Configures system fonts directly (requires XeLaTeX or LuaLaTeX):
```latex
\usepackage{fontspec}
\setmainfont{DejaVu Serif}
\setsansfont{DejaVu Sans}
\setmonofont{Courier New}
```

- **`xcolor`**: Comprehensive color management for backgrounds, text, and boxes:
```latex
\usepackage{xcolor}
\pagecolor{yellow!8} % Soft tinted page background
\definecolor{mnitblue}{RGB}{23, 75, 137}
\definecolor{highlightyellow}{HTML}{FEF3C7}
\colorlet{accentcolor}{red!60!yellow} % Mixes 60% red with 40% yellow
```
*Apply colors with `\textcolor{mnitblue}{Text}` or inline blocks `{\color{mnitblue} Text}`. Apply background highlights with `\colorbox{highlightyellow}{Text}` or framed boxes with `\fcolorbox{mnitblue}{white}{Text}`.*

#### 2.3 Headings & Title Generation

```latex
\documentclass[12pt, a4paper]{article}

\title{\textbf{Technical Computing \& Typesetting Report}}
\author{Aditya \\ ID: 2025UCP1043 \\ Department of Computer Science and Engineering}
\date{\today}

\begin{document}
\maketitle

\begin{abstract}
This guide provides an end-to-end overview of technical typesetting workflows, structured mathematical layouts, tabular presentations, automated citations, and Doxygen integration.
\end{abstract}
```

Sectioning hierarchy:
- `\section{Section Title}`
- `\subsection{Subsection Title}`
- `\subsubsection{Subsubsection Title}`

*Unnumbered headings*: Append an asterisk (e.g., `\section*{Preface}`) to suppress numbering and omit the entry from the Table of Contents.  
*Custom Numbering*: Re-format section numbering to alphabetical or Roman numerals using:
```latex
\renewcommand{\thesection}{\Alph{section}} % Numbers sections as A, B, C...
```

#### 2.4 Spacing Controls, Line Breaking, and Box Manipulation

- **Line & Paragraph Breaks**: Use `\\` for manual line breaks within paragraphs. Leave a blank line (or use `\par`) to delimit paragraphs.
- **Page Breaks**: Force hard page breaks using `\newpage`, or use `\clearpage` to flush all floating figures and tables before continuing.
- **Spacing Dimensions**: Set default indentation with `\setlength{\parindent}{1.5em}` and inter-paragraph gap with `\setlength{\parskip}{0.8em}`. Fine-tune local spacing using `\hspace{length}` and `\vspace{length}`.
- **Hyphenation Hints**: Suggest word breaks in long terms with `\-` (e.g., `hy\-per\-pa\-ram\-e\-ter`).
- **Dividers & Rules**: Insert horizontal rule dividers using `\rule{width}{thickness}` (e.g., `\rule{\linewidth}{0.5pt}`).

Common box environments used to position content:

```latex
% LR Boxes (Horizontal positioning)
\makebox[5cm][c]{Unframed Centered Text}
\framebox[5cm][r]{Framed Right-Aligned Text}

% Fixed-Width Paragraph Box with Automatic Word Wrap
\parbox{6cm}{This text is bound inside a 6cm fixed paragraph box and wraps automatically.}

% Vertical Alignment Adjustment
Baseline Text \raisebox{1ex}{Elevated Text} \raisebox{-1ex}{Submerged Text}

% Saveboxes (Declare once, render repeatedly)
\newsavebox{\brandbox}
\savebox{\brandbox}{\framebox[4.5cm][c]{\textbf{MNIT Jaipur - CSE}}}
\usebox{\brandbox}

% Non-Breaking Text
\mbox{Keep this text strictly on one unbroken line.}
\begin{samepage}
  Content wrapped within this block is protected from cross-page splitting.
\end{samepage}
```

---

### 3. Mathematical Notation & Data Tables

LaTeX is the industry gold standard for typesetting mathematical equations and scientific data tables.

#### 3.1 Math Environments

- **Inline Math**: Embedded in prose using `$...$` or `\(...\)` (e.g., $E = mc^2$).
- **Display Math**: Centered standalone formulas scoped with `\[...\]` or `\begin{equation}...\end{equation}`.

The `amsmath` package provides multi-line alignment environments:

- `equation`: Numbered standalone equation. (Use `equation*` to suppress numbering).
- `align` / `align*`: Aligns multiple equations at designated points marked with `&`:
```latex
\begin{align}
  \nabla \times \mathbf{E} &= -\frac{\partial \mathbf{B}}{\partial t} \\
  \nabla \cdot \mathbf{D} &= \rho
\end{align}
```
- `gather` / `gather*`: Multi-line equations centered independently without coordinate alignment.
- `multline` / `multline*`: For long formulas that span lines: the first line is left-aligned, intermediate lines are centered, and the final line is right-aligned.
- `cases`: Formats piecewise definitions:
```latex
f(x) = \begin{cases}
  x^2 + 2x + 1, & x < 0 \\
  \sqrt{x} + 1, & 0 \le x < 4 \\
  \dfrac{x^2 - 1}{x - 1}, & x \ge 4
\end{cases}
```

#### 3.2 Mathematical Symbols & Operators

- **Indices & Powers**: Subscripts with `_` and exponents with `^` (e.g., $x_{i,j}^2$).
- **Fractions & Roots**: `\frac{numerator}{denominator}` and `\sqrt[n]{expression}`.
- **Calculus**: Integrals `\int_{0}^{1} f(x)\,dx`, partials `\frac{\partial u}{\partial t}`, and derivatives `\frac{d^2 y}{dx^2}`.
- **Summations & Products**: `\sum_{k=1}^{n} k^2` and `\prod_{i=1}^{m} x_i`.
- **Dynamic Delimiters**: Auto-scaling braces using `\left(` and `\right)` (e.g., `\left( \frac{a+b}{c} \right)` or one-sided brackets `\right.`).
- **Over/Under Structures**:
```latex
\overbrace{a + b + c}^{\text{Group 1}} + \underbrace{x + y + z}_{\text{Group 2}} = \text{Total}
\binom{n}{k} = \frac{n!}{k!(n-k)!}
```

#### 3.3 Matrix Typesetting Environments

The `amsmath` package includes matrix environments for standard bracket types:

| Matrix Environment | Surrounding Brackets | Code Example |
| :--- | :--- | :--- |
| `matrix` | Plain (No brackets) | `\begin{matrix} 1 & 2 \\ 3 & 4 \end{matrix}` |
| `pmatrix` | Parentheses `()` | `\begin{pmatrix} a & b \\ c & d \end{pmatrix}` |
| `bmatrix` | Square brackets `[]` | `\begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix}` |
| `Bmatrix` | Curly braces `{}` | `\begin{Bmatrix} x & y \\ z & w \end{Bmatrix}` |
| `vmatrix` | Single vertical lines (Determinant) | `\begin{vmatrix} a_{11} & a_{12} \\ a_{21} & a_{22} \end{vmatrix}` |
| `Vmatrix` | Double vertical lines (Norm) | `\begin{Vmatrix} v_1 \\ v_2 \end{Vmatrix}` |
| `smallmatrix` | Compact inline matrix | `\left( \begin{smallmatrix} 1 & 2 \\ 3 & 4 \end{smallmatrix} \right)` |

#### 3.4 Professional Data Tables

To design clear, publication-quality tables:
- Combine column specifiers (`l` left, `c` center, `r` right, `p{width}` paragraph with auto-wrapping).
- Use `booktabs` rules (`\toprule`, `\midrule`, `\bottomrule`) and omit vertical lines.
- Highlight metrics using `colortbl` cell shading (`\cellcolor{...}`).

```latex
\documentclass{article}
\usepackage{booktabs}
\usepackage{xcolor}
\usepackage{colortbl}
\usepackage{multirow}

\definecolor{headerblue}{RGB}{23, 75, 137}
\definecolor{cellgreen}{RGB}{221, 241, 221}
\definecolor{cellyellow}{RGB}{254, 243, 199}
\definecolor{cellred}{RGB}{253, 226, 226}

\begin{document}

\begin{table}[ht]
\centering
\caption{Deep Learning Model Performance Evaluation}
\label{tab:model_evaluation}
\renewcommand{\arraystretch}{1.3}

\begin{tabular}{l c c c p{4.2cm}}
\toprule
\rowcolor{headerblue}
\textcolor{white}{\textbf{Model}} & 
\textcolor{white}{\textbf{Parameters}} & 
\textcolor{white}{\textbf{FLOPs}} & 
\textcolor{white}{\textbf{Accuracy (\%)}} & 
\textcolor{white}{\textbf{Notes}} \\
\midrule
ResNet18        & 11.7M & 1.82G & \cellcolor{cellgreen}94.21 & Reliable feature extraction; stable convergence. \\
MobileNetV2     & 3.5M  & 0.30G & \cellcolor{cellgreen}92.84 & Optimized for edge runtime deployment. \\
EfficientNet-B0 & 5.3M  & 0.39G & \cellcolor{cellgreen}93.52 & Optimal parameter-to-accuracy ratio. \\
Baseline CNN    & 2.1M  & 0.18G & \cellcolor{cellyellow}78.40 & Underfitting observed; requires deeper layers. \\
Experimental    & 0.8M  & 0.09G & \cellcolor{cellred}62.15   & Diverged during training; requires tuning. \\
\bottomrule
\end{tabular}
\end{table}

\end{document}
```

---

### 4. Figures, Basic Diagrams, and References

#### 4.1 Inserting Figures

Include graphics files (PNG, JPG, PDF) using `graphicx`:

```latex
\usepackage{graphicx}

\begin{figure}[ht]
  \centering
  \includegraphics[angle=18, width=0.45\textwidth]{mnit_logo.png}
  \caption{MNIT Logo rotated by 18 degrees.}
  \label{fig:mnit_logo}
\end{figure}
```

- **Cropping & Scaling**: `\includegraphics[trim=0 0 0 150, clip, width=\textwidth]{mnit_building.jpg}` trims padding before scaling.
- **Side-by-Side Images**: Wrap images inside `minipage` blocks:
```latex
\noindent
\begin{minipage}{0.48\textwidth}
  \centering
  \includegraphics[width=0.85\textwidth]{mnit_logo.png}
  \captionof{figure}{MNIT Emblem}
\end{minipage}\hfill
\begin{minipage}{0.48\textwidth}
  \centering
  \includegraphics[width=0.85\textwidth]{mnit_building.jpg}
  \captionof{figure}{Campus Building}
\end{minipage}
```

#### 4.2 Drawing with the `picture` Environment

LaTeX features a built-in vector graphics canvas:

```latex
\setlength{\unitlength}{1cm}
\begin{picture}(6, 4)(0, 0)
  \linethickness{1pt}
  \put(0, 0){\vector(1,0){5}}               % X Axis Vector
  \put(0, 0){\vector(0,1){3}}               % Y Axis Vector
  \put(1, 1){\line(2,1){3}}                 % Line with slope 2/1
  \put(2, 2){\circle{1.2}}                  % Circle of diameter 1.2cm
  \put(4, 2){\circle*{0.6}}                 % Filled disk of diameter 0.6cm
  \put(3, 3){\oval(2, 1)[t]}                % Top half of an oval
  \put(0.5, 2.2){\dashbox{0.15}(1.8, 0.8){Control Node}}
  \qbezier(0,2.5)(2,4)(4,2.5)               % Quadratic Bézier curve
  \multiput(0,0)(0.6,0){6}{\circle*{0.08}}  % Repeated dots pattern
\end{picture}
```

#### 4.3 Indexing & Bibliographies

##### Document Indexing (`makeidx`)

1. **Preamble Setup**:
   ```latex
   \usepackage{makeidx}
   \makeindex
   ```
2. **Index Tagging in Text**:
   - Standard: `\index{matrices}`
   - Sub-entry: `\index{matrices!determinant}`
   - Page range: `\index{calculus|(}` ... `\index{calculus|)}`
   - Cross-reference: `\index{FLOPs|see{Performance}}`
3. **Render Index**: Place `\printindex` at the end of the document.
4. **Build Chain**: Run `pdflatex doc` $\rightarrow$ `makeindex doc.idx` $\rightarrow$ `pdflatex doc`.

##### Bibliography Management (`natbib` & BibTeX)

Store citation sources in a `.bib` database (e.g., `physics.bib`):

```bibtex
@article{einstein1905,
  author = {Albert Einstein},
  title = {Zur Elektrodynamik bewegter K{\"o}rper},
  journal = {Annalen der Physik},
  volume = {322},
  number = {10},
  pages = {891--921},
  year = {1905}
}

@book{oetiker2021,
  author = {Tobias Oetiker},
  title = {The Not So Short Introduction to LaTeX 2e},
  publisher = {CTAN},
  year = {2021}
}
```

Include references in your `.tex` document:
```latex
\usepackage{natbib}

% In document body:
According to \citet{einstein1905}, mass and energy are equivalent.

\bibliographystyle{plain}
\bibliography{physics}
```
Build pipeline: `pdflatex doc` $\rightarrow$ `bibtex doc` $\rightarrow$ `pdflatex doc` $\rightarrow$ `pdflatex doc`.

