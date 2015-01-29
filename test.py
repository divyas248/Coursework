def play():
    ''' () -> ()
    
        Starts a game of 2-Player Sudoku
    '''
    size()
    game(size) # Initializes game
    show(game)
    
    for i in range(size**2):
        while i%2:
            l = input("Player A please enter a move: ").split(', ')
            row, column, move = l[0], l[1], l[2]
            if move == 'q':
                quit
            elif move == 's':
                save()
            row, column, move = int(row), int(column), int(move)
            if check_move(row, column, move) == True:
                game[row][column] = move
                show(game)
                if check_win() == 0:
                    break
                elif check_win() == 1:
                    print("Player A wins!")
                    i = size**2
                    save()
                elif check_win() == 2:
                    print("The game is tied.")
                    i = size**2
                    save()
            i += 1
                    
        while i%2 == 1:
            l = input("Player B please enter a move: ").split(', ')
            row, column, move = l[0], l[1], l[2]
            if move == 'q':
                quit 
            elif move == 's':
                save()    
            row, column, move = int(row), int(column), int(move)
            if check_move(row, column, move) == True:
                game[row][column] = move
                show(game)
                if check_win() == 0:
                    break
                elif check_win() == 1:
                    print("Player B wins!")
                    i = size**2
                    save()
                elif check_win() == 2:
                    print("The game is tied.")
                    i = size**2
                    save()
            i += 1
def size():
    ''' () -> int

        Asks for the grid size (either 4, 9 or 16)
        Will continue to ask if not one of the three options
        Returns size
    '''
    while True:
        global size
        size = int(input("Please enter a grid size: "))
        if size == 4 or size == 9 or size == 16:
            return size
        else:
               print("You have entered an invalid size. Please try again")

def game(size):
    ''' (int) -> list
        
        Returns game (a matrix of zeros of size x size)
    '''
    global game
    game = []
    for i in range(size):
        game.append([])
        for j in range(size):
            game[i].append(0)
    return game

def show(game):
    ''' (list) -> ()

        Prints the matrix game in sudoku format
    '''
    for i in range(len(game)):
        if i%size**(1/2) == 0 and i != 0:
                print('-' * size * 2)
        for j in range(len(game)):
            if j%size**(1/2) == 0 and j != 0:
                print('|', end = '')
            print(game[i][j], end = '')
            if j%size**(1/2) != size**(1/2) - 1:
                print(' ', end = '')
            elif j == len(game) - 1:
                print('')

def check_move(row, column, move):
    ''' (int, int, int) -> boolean

        Checks the row and column of the inputted move to see if the same move
        exists. If it does, return False
        Calls separate functions to check the boxes
    '''
    if row > size - 1 or column > size - 1 or move > size:
        return False
    
    elif game[row][column] != 0:
        return False
    
    for j in range(size):
        if game[row][j] == move or game[j][column] == move:
            return False #Check row and column of designated square
        
    #Checking boxes
    if size == 4:
        check_move_4(row, column, move)

def check_move_4(row, column, move):
    ''' (int, int, int) -> boolean

        Checks the 2x2 squares of a 4x4 game to see if the move is valid
        Returns false if the move is invalid
        Returns true if the move is valid   
    '''
    if row <= 1 and column <= 1:
        for k in range(2):
            for l in range(2):
                if game[k][l] == move:
                    return False               
    elif row <= 1 and column >= 1:
        for k in range(2):
            for l in range(2):
                if game[k][l+2] == move:
                    return False                
    elif row >= 1 and column <= 1:
        for k in range(2):
            for l in range(2):
                if game[k+2][l] == move:
                    return False                
    else:
        for k in range(2):
            for l in range(2):
                if game[k+2][l+2] == move:
                    return False
    return True

if __name__ == "__main__":
    play()
