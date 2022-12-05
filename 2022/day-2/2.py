with open("inp.in", "r") as inputfile:
    # 0 -> opponent
    # 1 -> you
    strategydata = [x.removesuffix("\n").split(" ") for x in inputfile.readlines()]

"""
x -> need to lose
y -> need to draw
z -> need to win
"""

CASES = {
    "Y": {
        # draw -> + 3pt
        "A": 4, # his rock i have to do rock -> 1 (rock) + 3 (draw)
        "B": 5, # his paper -> my paper -> 2 + 3
        "C": 6,
    },

    "Z": {
        # win -> + 6pt
        "A": 8, # his rock, my paper -> 2 (paper) + 6 (win)
        "B": 9, # his paper, my scissors
        "C": 7,
    },

    "X": {
        # lose -> +0pt
        "A": 3, # his rock, my scissors -> 3 (scissors) + 0(lost)
        "B": 1,
        "C": 2,
    }
}


total_score = 0
for turn in strategydata:
    total_score += CASES[turn[1]][turn[0]]

print(total_score)