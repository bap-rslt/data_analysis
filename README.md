# Data Analysis and Statistics Utility in C

## Project Overview

This project provides a C source file, `stats.c`, containing functions for data analysis and statistics. The functions are designed for analyzing datasets organized as columns and can calculate various statistics, such as mean, minimum, maximum, standard deviation, median, quartiles, and can also remove extreme values.

## Functions Available

The project provides the following functions in `stats.c`:

- `affiche_list(Col *col)`: Print the elements of a given column.
- `taille(Col *col)`: Calculate the size (number of elements) of a column.
- `moyenne(Col *col)`: Calculate the mean (average) of a column.
- `min(Col *col)`: Find the minimum value in a column.
- `max(Col *col)`: Find the maximum value in a column.
- `ecart_type(Col *col)`: Calculate the standard deviation (ecart-type) of a column.
- `mediane(Col *col)`: Find the median value of a column.
- `q1(Col *col)`: Calculate the first quartile value of a column.
- `q3(Col *col)`: Calculate the third quartile value of a column.
- `supExtremes(Col *col)`: Remove extreme values from a column using a specified factor `k`.

## How to Use

1. Include the `stats.c` source file in your C project.

2. Use the provided functions from `stats.c` to analyze and calculate statistics for your data columns.

