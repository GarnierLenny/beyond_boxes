# beyond_boxes

beyond_boxes is a sokoban replica made with C and ncurses

Once you have cloned the repo and downloaded the ncurses library, execute the "play_script" script by typing in a terminal "./play_script".

If you want to play with a custom map you have an example file named "exmaple_map" which shows how a map is done.

# custom map conception

For custom maps:
    '#': walls player and boxes cannot go through
    'P': player position, you will move your character from this position
    'X': boxes, player can move them by pushing them, can only move if the box's next position is a empty space
    'O': holes, to complete the level player must cover every holes with boxes

Every line of your map must end with a breakline, don't forget it !

Once your custom map is complete, execute "./play_script {path_to_map}" in order to be able to play with your custom map.
Exexute example: "./play_script example_map"

# online mode

To play online mode:
    You first need to stop your firewall from blocking client connection

    Fedora users:
        1. systemctl stop firewalld
        2. systemctl start firewalld

    Then make sure that all the players are connected to the same network.
    All the players must have the file map.
    All the players must know the host's IPv4.

    Steps:
        1. The host launch the play_script with the custom map as argument
        2. The host must go to "PLAY ARGUMENT MAP > HOST" then type his IPv4
        3. The host must finally select the total players slot with 'z' and 's' then press ENTER
        4. All the clients now must launch the play_script with the custom map as argument
        5. All the clients must go to "PLAY ARGUMENT MAP > JOIN" then type host's IPv4
        6. If "Press space to launch" is displayed on everyones screens congratulations you did it !
        7. When someone presses SPACE his game will start and so his timer

This project isn't finished yet, i'll keep you up to date.

Thanks for playing ! Don't hesitate to rate or give me feedback.
