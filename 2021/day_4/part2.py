#get data
with open("test.in", "r") as f:
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
    


last_board = None
wonboards = 0

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
            wonboards += 1

            # detect that it has been last checked -> all boards must win
            if wonboards == len(boards):
                last_board = n_board
                print("donwS")
                break
    
    if last_board:
        break

print(boards)

#calculate points
points = 0
for row in boards[last_board]:
    for elem in row:
        if elem != "":
            points += int(elem)
points *= int(number)

print(points)