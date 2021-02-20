# beyond_sokoban
beyond_sokoban is a sokoban replica made with C and ncruses

Once you have cloned the repo and downloaded the ncurses library, execute the "play_script" script by typing in a terminal "./play_scipt".

If you want to play with a custom map you have an example file named "exmaple_map" which shows how a map is done.

For custom maps:
    '#': walls player and boxes cannot go through
    'P': player position, you will move your character from this position
    'X': boxes, player can move them by pushing them, can only move if the box's next position is a empty space
    'O': holes, to complete the level player must cover every holes with boxes

Every line of your map must end with a breakline, don't forget it !

Once your custom is complete, execute "./play_script {path_to_map}" to be able to play with your custom map.
Exexute example: "./play_script example_map"

This project isn't finished yet, i'll keep you up to date.

Thanks for playing ! Don't hesitate to rate or give me feedback.