#include <iostream>
#include <cstdlib> // for random numbers
#include <ctime> // for different time stamps

using namespace std;

class HitGame{
	private:
		int NoOfPlayers, ourHits, enemyHits;
		
	public:
		// Constructor
		HitGame(int Players){
			NoOfPlayers = Players;
			// when the object is initialized, then both hits starts with zero
			ourHits = 0;
			enemyHits = 0;
			
			// seeding a different generation of random numbers everytime.
			
			srand(time(0)); 
			
			// the constructor should also automatically start the game as well.
			startGame();
		}
		
		void startGame(){
			// we have to keep the game running as long as the player counts reach
			for (int i = 0; i < NoOfPlayers; i++){
				int rand1 = rand() % 5; //random numbers b/w 0 to 4 to maximize the possibilities of hits
				int rand2 = rand() % 5;
				
				cout << "Attack no: " << i+1 << endl;
				
				if (rand1 == rand2){
					cout << "We hit the enemy!" << endl;
					ourHits++;
				} else {
					cout << "We got hit :( " << endl;
					enemyHits++;
				}
			}
			gameSummary(); // Final output of the game! 
		}
		
		void gameSummary() {
			cout << "Our Hits: " << ourHits << endl;
			cout << "Enemy Hits: " << enemyHits << endl;
			
			if(ourHits > enemyHits){
				cout << "We Won!" << endl;
			} else if(enemyHits > ourHits){
				cout << "We lose!" << endl;
			} else {
				cout << "Game tied!" << endl;
			}
		}
	
	
};

int main(){
	srand(time(0)); 
	int players = rand() % 4;
	cout << "Number of Players: " << players << endl;
	
	HitGame game1(players);	
	
	
	
	return 0;
}
