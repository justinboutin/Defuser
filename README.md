# Defuser
A simple c++ class that allows the user to attempt to diffuse a bomb based off some simple rules.

RULES
1. FIRST RULE
- You must start with a white or red wire.


2. SECOND RULE
- If you picked white, you can either cut white or black.
- If you picked red, you can either cut red or black.


3. THIRD RULE
- If you picked two white wires, you must cut black.
- If you picked two red wires, you must cut black.
- If you picked different color wires, you must cut orange.


4. FOURTH RULE
- If you picked black, cut green then orange to defuse the bomb.
- If you picked orange, cut the green wire to defuse the bomb.
