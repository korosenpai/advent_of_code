#get data
with open("inp.in", "r") as f:
    data = [x.strip("\n") for x in f.readlines()]

numbers_drawn = data[0].split(",")
# print(numbers_drawn)
# print("-"*50, "\n")

data = data[2:] # remove first two lines


#get boards
boards = []

temp_board = []
for i in data:
    if i == "":
        boards.append(temp_board)
        temp_board = []
    
    else:
        temp_board.append(i.split())

if temp_board:
    boards.append(temp_board)
del temp_board

#print boards (for clarity when debugging)
# for board in boards:
#     for row in board:
#         print(row)
#     print("\n")

# print("-"*50, "\n")


def check_bingo(board):
    #horizontal
    for row in board:
        if not "".join(row):
            return True

    #verticaL
    for n_elem in range(len(board[0])):
        if not "".join([board[n_row][n_elem] for n_row in range(len(board))]):
            return True
    
    return False
    


lowest_draw = None # lowest number to get to bingo a board
wboard_index = None


#pick numbers
for n_number, number in enumerate(numbers_drawn):

    #do one board at a time
    for n_board, board in enumerate(boards):
        
        #remove number from board if found with ""
        for n_row, row in enumerate(board):            
            row = ["" if x == number else x for x in row]
            board[n_row] = row
        
        # check if bingo
        if check_bingo(board):
            if not lowest_draw:
                lowest_draw = n_number

            lowest_draw = min(n_number, lowest_draw)
            
            if lowest_draw == n_number:
                wboard_index = n_board

            break
    
    if wboard_index:
        break

print(boards)
print(numbers_drawn[lowest_draw])

#calculate points
points = 0
for row in boards[wboard_index]:
    for elem in row:
        if elem != "":
            points += int(elem)
points *= int(number)

print(points)