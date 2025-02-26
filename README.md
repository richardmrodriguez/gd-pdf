# gd-pdf
## A simple wrapper for pdfio for use in the Godot 4.3 engine

This wrapper is meant to add some basic PDF reading and parsing functionality to Godot. I have a specific, limited-scope use case for this. Therefore, this wrapper will not be exhaustive, and will simplify many things and exclude certain advanced features.

The main goals of this are to:

- Parse the PDF document
- Get a "raw-ish" extraction of the text for each page of a PDF, including:
    - The proper UTF-8 string of each character (including CJK / Cyrillic, etc.)
    - The exact x, y coordinates of each character
    - The font size in points for each character
    - The name of the font for each character
    - Maybe font extraction? Or at least font metrics extraction


So, this wrapper is not concerned with extracting images or tables or other things like that.

## Attribution / Licensing

gd-pdf is licensed under the MIT license. 

This means that commercial use is allowed, but please provide proper attribution and provide copies of the proper licensing when using this in a commercial game, for example.

[pdfio](https://github.com/michaelrsweet/pdfio) is licensed under the Apache 2.0 license.

