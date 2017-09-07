# Absolver-Deck-Map

## Description
This is a simple program for use with the game Absolver. It converts 1920x1080 screenshots of the deck editor screen into a map representation so that you can visualize the flow of your combos.

## Examples
You can view some examples [here](https://imgur.com/a/LSNCl).

## Usage
1. Download the folder; unzip it if necessary.
2. Take a 1920x1080 screenshot of the deck edit screen in your game. See the note below about image formats.
3. Drag and drop one or more of these screenshots onto the "AbsolverDeckMapper.exe" executable.
4. A window will open showing that status of processing each image.
5. Once the processing is complete, you may close the window.
6. You will have a new deck map image in the same folder as each of the screenshots you imported.

### Note About Image Formats
It is important that you take your screenshot in a lossless image format. In most cases, this means PNG. Formats like JPG use lossy compression, and this can actually change the colors of certain pixels. To determine which stances moves end in, the program looks at the colors of pixels in certain spots in the image. This is why the image you use must be an exact representation of what your screen looks like in game. On Windows 10, pressing the "Print Screen" key on your keyboard copies a PNG screenshot to your clipboard. You can then paste it into paint or any other image editor and save it as a PNG to be used in the Deck Mapper.

## How the Maps Work
* **Blue lines** indicate that pressing the **regular attack** button will execute the move being pointed to.
* **Yellow lines** indicate that pressing the **alternate attack** button will execute the move being pointed to.
* **Grey lines** indicate that **waiting a moment** for your combo to reset will put you in the stance being pointed to.