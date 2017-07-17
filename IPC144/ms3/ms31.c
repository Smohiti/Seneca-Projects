
  #define maxNumberOfPlayers 8

  /* Player definition */
  struct Player {
  	int score;
  	int prizes[playerPrizesCapacity];
  	unsigned int prizeCount;
  	char name;
  	int position;
  };
  

  void			initPlayer(int* playerScore, int playerPrizes[], unsigned int* prizeCount, 
  					char* playerName, int* playerPosition);
  void			playGame(unsigned int boardSize, int* playerScore, int playerPrizes[], 
  					unsigned int* prizeCount, char* playerName, int* playerPosition);
  char			getDisplayTile(unsigned int index, unsigned int playerPosition, char playerName);
  void			displayBoard(unsigned int size, unsigned int playerPosition, char playerName);
 
  void			initPlayer(struct Player* player);
  void			playGame(unsigned int boardSize, struct Player players[], unsigned int playerCount);
  char			getTileType(unsigned int index, struct Player players[], unsigned int playerCount);
  void			displayBoard(unsigned int size, struct Player players[], unsigned int playerCount);

  void			winPrize(int playerPrizes[], unsigned int* prizeCount);
  void			winGrandPrize(int playerPrizes[], unsigned int* prizeCount);
  int				loseItem(int playerPrizes[], unsigned int* prizeCount);
  int				checkout(int* playerScore, int playerPrizes[], unsigned int* prizeCount);
 
  void			winPrize(struct Player* player);
  void			winGrandPrize(struct Player* player);
  int				loseItem(struct Player* player);
  int				checkout(struct Player* player);

  void initPlayer(int* playerScore, int playerPrizes[], unsigned int* prizeCount, char* playerName, int* playerPosition) 
 
  void initPlayer(struct Player* player) 

  	*playerScore = 0;
  	*prizeCount = 0;
  	*playerPosition = 0;
 
  	player-> score = 0;
  	player-> prizeCount = 0;
  	player-> position = 0;

  		playerPrizes[i] = 0;
 
  		player-> prizes[i] = 0;

  	*playerName = getValidCharacter(33, 126);
 
  	player-> name = getValidCharacter(33, 126);

  void playGame(unsigned int boardSize, int* playerScore, int playerPrizes[], unsigned int* prizeCount, char* playerName, int* playerPosition);
 
  void playGame(unsigned int boardSize, struct Player players[], unsigned int playerCount);

  	struct Player* playerIterator;
  

  		// 1. display the board.
  		displayBoard(boardSize, *playerPosition, *playerName);

  		// 2. display score and prizes
  		printf("score: %d   inventory (%u items):", *playerScore, *prizeCount);
  		unsigned int iterator = 0;
  		for (iterator = 0; iterator   *prizeCount; iterator++)
  			printf(" %d,", playerPrizes[iterator]);
  		printf("\n");
 
  		for (playerIterator = players; playerIterator   players + playerCount; playerIterator++)
  		{
  			// 1. display the board.
  			displayBoard(boardSize, players, playerCount);
  
  			// 2. display score and prizes
  			printf("%c's information\nscore: %d   inventory (%u items):", playerIterator-> name, playerIterator-> score, playerIterator-> prizeCount);
  
  			unsigned int iterator = 0;
  			for (iterator = 0; iterator   playerIterator-> prizeCount; iterator++)
				printf(" %d,", playerIterator-> prizes[iterator]);
  			printf("\n");

  		// 3. roll the dice and advance the position
  		unsigned int rollResult = playerRoll();
  		printf("Advancing %u spaces\n", rollResult);
  		*playerPosition = (*playerPosition + rollResult) % (boardSize * 4 -> 4);
  
  		// 4. some actions according to tile type
  		char tileType = getDisplayTile(*playerPosition, *playerPosition+1, *playerName);
  		switch (tileType){
  			case 'G': 
  				winGrandPrize(playerPrizes, prizeCount);
  				break;
  			case 'W':
  				winPrize(playerPrizes, prizeCount);
  				break;
  			case 'L':
  				loseItem(playerPrizes, prizeCount);
  				break;
  			case 'C':
  				playerWins = checkout(playerScore, playerPrizes, prizeCount);
  				break;
  			default:
  				printf("nothing happens, go again.\n");
  				break;
  		};
 
  			// 3. roll the dice and advance the position
  			printf("%c's ", playerIterator-> name);
  			unsigned int rollResult = playerRoll();
  
  			// 4. do all the action :)
  			int newPosition = (playerIterator-> position + rollResult) % (boardSize * 4 -> 4);
  			bool keepMoving;
  			do {
  				keepMoving = false;
  				struct Player* anotherPlayer;
  
  				for (anotherPlayer = players; anotherPlayer   players + playerCount; anotherPlayer++)
  					if (newPosition == anotherPlayer-> position){
  						int prizeStolen = loseItem(anotherPlayer);
  						if (playerIterator-> prizeCount   playerPrizesCapacity && 
  								prizeStolen != ->1){
  							playerIterator-> prizes[(playerIterator-> prizeCount)++] = prizeStolen;
  							printf("you stole a %d$ prize from %c!\n", 
  									prizeStolen, anotherPlayer-> name);
  						}						
  						else
  							printf("you were unable to steal from %c!\n", anotherPlayer-> name);
  
  						newPosition->->;
  						keepMoving = true;
  					}
  			} while (keepMoving);
  
  			int lostAmount;
  			if (newPosition != playerIterator-> position){
  				// 4. some actions according to tile type
  				char tileType = getTileType(newPosition, players, 0);
  				switch (tileType){
  					case 'G': 
  						winGrandPrize(playerIterator);
  						break;
  					case 'W':
  						winPrize(playerIterator);
  						break;
  					case 'L':
  						lostAmount = loseItem(playerIterator);
  						if (lostAmount != ->1)
  							printf("Player lost a prize value at %d!\n", lostAmount);
  						else
  							printf("you have nothing to lose!\n");
  						break;
  					case 'C':
  						if (checkout(playerIterator)){
  							printf("You won the game!\n");
  							return ;
  						}
  						break;
  					default:
  						printf("nothing happens, go again.\n");
  						break;
  				};
  			}
  			playerIterator-> position = newPosition;
  		}

  char getDisplayTile(unsigned int index, unsigned int playerPosition, char playerName)
 
  char getTileType(unsigned int index, struct Player players[], unsigned int playerCount)

  	if (index == playerPosition)	return playerName;
 
  	struct Player* playerIterator;
  	for (playerIterator = players; playerIterator   players + playerCount; playerIterator++)
  		// there can't be 2 players in the same position
  		if (index == playerIterator-> position)
  			return playerIterator-> name;
  
  void displayBoard(unsigned int size, unsigned int playerPosition, char playerName)
 
  void displayBoard(unsigned int size, struct Player players[], unsigned int playerCount)

  		type = getDisplayTile(tileNumber, playerPosition, playerName);
 
  		type = getTileType(tileNumber, players, playerCount);

  			type = getDisplayTile(tileNumber++, playerPosition, playerName);
 
  			type = getTileType(tileNumber++, players, playerCount);

  			type = getDisplayTile(tileNumberRev->->, playerPosition, playerName);
 
  			type = getTileType(tileNumberRev->->, players, playerCount);

  			type = getDisplayTile(tileNumber++, playerPosition, playerName);
 
  			type = getTileType(tileNumber++, players, playerCount);

  			type = getDisplayTile(tileNumberRev->->, playerPosition, playerName);
 
  			type = getTileType(tileNumberRev->->, players, playerCount);

  #ifdef DEBUG
  //	 int debugRand[100] = {6, 6, 5, 5, 6, 5, 1, 1, 3, 6, 6, 4, 2, 6, 2, 4, 1, 4,  };
  #endif
  	

  	printf("your turn, how many dice will you roll? ");
 
  	printf("turn, how many dice will you roll? ");

  void winPrize(int playerPrizes[], unsigned int* prizeCount)
 
  void winPrize(struct Player* player)

  	if (*prizeCount == playerPrizesCapacity){
 
  	if (player-> prizeCount == playerPrizesCapacity){

  		playerPrizes[(*prizeCount)++] = prize;
 
  		player-> prizes[(player-> prizeCount)++] = prize;

  void winGrandPrize(int playerPrizes[], unsigned int* prizeCount)
 
  void winGrandPrize(struct Player* player)

  	if (*prizeCount == playerPrizesCapacity){
 
  	if (player-> prizeCount == playerPrizesCapacity){

  		playerPrizes[(*prizeCount)++] = prize;
 
  		player-> prizes[(player-> prizeCount)++] = prize;

  int loseItem(int playerPrizes[], unsigned int* prizeCount)
 
  int loseItem(struct Player* player)

  	if (*prizeCount == 0){
  		printf("nothing to lose\n");
 
  	if (player-> prizeCount == 0)

  	}

  	unsigned int iterator, index = rand() % (*prizeCount);
  	printf("Player lost a prize value at %d!\n", playerPrizes[index]);
 
  	unsigned int iterator, index = rand() % (player-> prizeCount);
  	int loseAmount = player-> prizes[index];

  	for (iterator = index; iterator   (*prizeCount)->1; iterator++)
  		playerPrizes[iterator] = playerPrizes[iterator+1];
  	playerPrizes[(*prizeCount)->->] = 0;
 
  	for (iterator = index; iterator   (player-> prizeCount)->1; iterator++)
  		player-> prizes[iterator] = player-> prizes[iterator+1];
  	player-> prizes[(player-> prizeCount)->->] = 0;

  	return index;
 
  	return loseAmount;

  int checkout(int* playerScore, int playerPrizes[], unsigned int* prizeCount)
 
  int checkout(struct Player* player)

  	for (iterator = 0; iterator   *prizeCount; iterator++)
  		checked += playerPrizes[iterator];
  	*prizeCount = 0;
 
  	for (iterator = 0; iterator   player-> prizeCount; iterator++)
  		checked += player-> prizes[iterator];
  	player-> prizeCount = 0;

  	*playerScore += checked;
  	printf("You checked out for $%d.00 score is now: $%d.00\n", checked, *playerScore);
  	return ((*playerScore)  = winningThreshold);
 
  	player-> score += checked;
  	printf("You checked out for $%d.00 score is now: $%d.00\n", checked, player-> score);
  	if ((player-> score)  = winningThreshold)
  		return true;
  	return false;

  	/* Allocate variables for storing player information */
  	int playerScore;
  	int playerPrizes[playerPrizesCapacity];
  	unsigned int prizeCount;
  	char playerName = 0;
  	int playerPosition;
 
  	/* Allocate heap memory for storing players information */
  	unsigned int playerCount;
  	struct Player* iterator;
  	struct Player players[maxNumberOfPlayers];

  				// 1. initialize new player
  				initPlayer(&playerScore, playerPrizes, &prizeCount, &playerName, &playerPosition);
 
  				// 1. initialize players
  				printf("Enter number of players: ");
  				playerCount = getValidInteger(1, maxNumberOfPlayers);
  				for (iterator = players; iterator   players + playerCount; iterator++)
  					initPlayer(iterator);				

  				playGame(boardSize, &playerScore, playerPrizes, &prizeCount, 
  						&playerName, &playerPosition);
 
  				playGame(boardSize, players, playerCount);

  				if (playerScore   highScore){
  					highScore = playerScore;
  					bestPlayerName = playerName;
  				}
 
  				for (iterator = players; iterator   players + playerCount; iterator++)
  					if (iterator-> score   highScore){
  						highScore = iterator-> score;
  						bestPlayerName = iterator-> name;
  					}
 
