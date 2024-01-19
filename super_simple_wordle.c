#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define N 5 //letter number
#define W 100 //word count in database
#define A 5 //attempt number [changeable]

char str_database[(W*(N+1))+1] = "BRAVE-CLOUD-BROWN-DRAWS-FIXED-KICKS-QUOTA-MIXER-JUMPS-YOKED-FLOWY-TIGER-CYNIC-RIPEN-WOVEN-LIARS-QUIRK-HYMNS-ZEBRA-FLUTE-VOLTS-JOCKY-GAMER-SPINY-NIXON-CHALK-WIRED-FLASK-SKIMP-YACHT-CHIRP-ZEALO-TAXIS-FIXER-YOGIS-CLAMP-JOUST-GRIND-FROWN-EXALT-VIXEN-HULKY-KNEAD-CRISP-BEGUN-MINUS-RAINY-DOZER-SQUAD-THUMP-FLINT-WAIST-DRIFT-VINYL-PLOWY-BLITZ-WRONG-JOLTY-AXIOM-BLIMP-FROZE-DREAM-PLUMB-JOKER-SKIRT-HIKER-SLUMP-MIXES-TOMBS-JOYED-WRIST-QUOTE-BROIL-FROST-HAVEN-DRONE-HAWKS-HIRES-GLOVE-PLUTO-CHASM-QUIPS-FRISK-NOVAE-MIXUP-HYING-WRECK-PLUCK-YELPS-WOKED-FIORD-AUDIO-ROCKS-BLOWS-SHADY-POWER-MOUSE-CROWN-CLOWN-CRUSH";

int main()
{
	srand(time(NULL));
	
	char t[N+1], g[N+1], dummy[2], str_temp[N+1];
	int i, j, temp, r, cont;
	
	do
	{
		r = rand() % W; //getting random number
		strncpy(str_temp, str_database+(r*(N+1)), N); //choosing random word according to random number
		
		strcpy(t, str_temp);
		strcpy(dummy, " ");
		
		printf("Welcome to Wordle!\n");
		
		for(i = 0; i < A; i++)
		{		
			printf("--Attempt #%d/%d--\n", i+1, A);
			printf("Your guess: ");
			
			fgets(g, N+1, stdin);
			g[strcspn(g, "\n")] = '\0';
			getchar();
			
			strcpy(g, strupr(g)); //making input uppercase
			
			printf("Result: ");
			for(j = 0; j < N; j++)
			{
				dummy[0] = g[j];
				temp = strcspn(t, dummy);
				
				if(temp == j) //letter exists and in the correct position
				{
					printf("%c ", g[j]); //letter is already uppercase
				}
				else if(temp < N-1) //letter exists
				{
					printf("%c ", tolower(g[j])); //making letter lowercase
				}
				else //letter does not exist
				{
					printf("_ ");
				}
			}
			printf("\n\n\n");
			
			if(strcmp(t, g) == 0) //if problem is solved, end the loop
				break;
		}
		
		if(strcmp(t, g) == 0)
		{
			printf("You win!\nThe word was: %s\n\n\n", t);
		}
		else
		{
			printf("Out of attempts! You lose!\nThe word was: %s\n\n\n", t);
		}
		
		printf("--------------------------------------------------------\n");
		printf("Do you want to play again? Enter 1 for yes, 0 for no.\n");
		scanf("%d", &cont);
		getchar();
		printf("--------------------------------------------------------\n\n\n\n\n");
	}
	while(cont == 1);
	
	return 0;
}