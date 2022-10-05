print("Let's play tic tac toe!")
board = [" "]
board.extend("a b c\n1 | | \n ------\n2 | | \n ------\n3 | | ")
respos = {"a1" : 0, "b1" : 0, "c1" : 0, "a2" : 0, "b2" : 0, "c2" : 0, "a3" : 0, "b3" : 0, "c3" : 0}
playerpos = ("a")
boardindex = 1
print("".join(board))
x_or_o = ("x")
win = False
turncount = 0
#glossary
#board:a list containing elements for the board
#respos: reserved positions, where you can and can't go.
#0 means that no one is in that square, 1 means that player "x" is in that square
#2 means that player "o" is in that square.
#playerpos: player position, on the board (eg. a1 for the top left square)
#boardindex: what index in the list to change to an x or o
#boardprint: a join-ed version of the board, for printing
#x_or_o: turn indicator
#win: tells if someone won
#turncount: what turn in the game you're on

def wincheck():
    global win
    #just a list of all the winning position combos
    winpos =  { 0 : ["a1", "b1", "c1"], 1 : ["a2", "b2", "c2"], 2 : ["a3", "b3", "c3"],
                3 : ["a1", "a2", "a3"], 4 : ["b1", "b2", "b3"], 5 : ["c1", "c2", "c3"],
                6 : ["a1", "b2", "c3"], 6 : ["a3", "b2", "c1"]}
    for i in winpos:
        count = 0
        count1 = 0
        #what this code is supposed to do is check reserved positions to see if anyone has a winning combo
        #it looks at every winning combo and if a player is in a position in that combo adds 1 to a counter
        #there are 2 counters, each for diffrent players. if a counter reaches 3 then that player wins
        resposcheck = winpos[i]
        for x in resposcheck:
            #im going insane from naming variables please help
            rescross = respos[x]
            match rescross:
                case 1:
                    count = count + 1
                case 2:
                    count1 = count1 + 1
                case 0:
                    #idk what i should do here if anything, the only reason its an elif is for error checking
                    pass
                case _:
                    print("there has been a strange error, or in other words, the programmer screwed up")
                    break
            if count == 3:
                print("Player X has won!")
                win = True
                return win
            elif count1 == 3:
                print("Player O has won!")
                win = True
                return win
    
#credit for the first dict code to edwin in the junferno discord :) thanks!
#turn function, works for both players
def turn():
    global playerpos
    global boardindex
    global respos
    global x_or_o
    print("Player " + x_or_o + ", your turn!")
    pos_dict = { "a1" : 8, "b1" : 10, "c1" : 12, "a2" : 23, "b2" : 25, "c2" : 27, "a3" : 38, "b3" : 40, "c3" : 42 }
    while True:
        playerpos = input("put the position you want here (eg. a1): ")
        try:
            #this changes playerpos into an index to change the board, try exept statement is for making sure input if valid
            boardindex = pos_dict[playerpos]
            respos_stat = respos[playerpos]
        except:
            print("wtf did you type?!")
            continue
        if respos_stat >= 1:
            print("You can't go there:(")
            continue
        else:
            board[boardindex] = x_or_o
            if x_or_o == "x":               
                respos[playerpos] = 1
            else:
                respos[playerpos] = 2
            print("".join(board))
            if x_or_o == "x":
                x_or_o = ("o")
                break
            else:
                x_or_o = ("x")
                break
    return playerpos
    return boardindex
    return respos
    return x_or_o
                
for i in range(0,9):
    turn()
    turncount+=1
    wincheck()
    if win == True:
        break
    if turncount == 9:
        print("Draw!")
        break