# Defuser
A simple c++ class that allows the user to attempt to diffuse a bomb based off some simple rules.

RULES
1. You must start with a white or red wire.

2. If you picked white, you can either cut white or black.
- If you picked red, you can either cut red or black.

3. If you picked two white wires, you must cut black.
- If you picked two red wires, you must cut black.
- If you picked different color wires, you must cut orange.

4. If you picked black, cut green then orange to defuse the bomb.
- If you picked orange, cut the green wire to defuse the bomb.
