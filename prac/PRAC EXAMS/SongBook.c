//happy birthday hailey
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 0XA
#define strSIZE 255

typedef enum {TRUE, FALSE} boolean;
typedef char string[strSIZE];

typedef struct{
	string ArtistName;
	string ArtistID; 
	string RecordLabel;
	int yearBorn;
}ArtistType;

typedef struct{
	int minutes;
	int seconds;
}Length;

typedef struct{
	string SongID;
	string SongName; 
	string ReleaseDate;
	string genre;
	Length songLength;
}SongType;

typedef struct{
	ArtistType Artist; 
	SongType ArtistSong[255];
}Discography;

typedef struct node{
	Discography List; 
	boolean status; // TRUE if song is sung, FALSE if song is not yet sung
	struct node* next;
}*nodePtr;

typedef nodePtr SongBook[SIZE]; //each bucket in the dictionary corresponds to an aritst

typedef struct{
	nodePtr front, rear;
}SongQueue; 

typedef struct{
	Discography D; 
	int top;
}*SongStack;

void initSongBook(SongBook A);
void displaySongs(SongBook A);
void displayQueue(SongQueue Q);

int hash(char *IDLetter); 
boolean isMember(SongBook A, char *IDSong);
boolean isDone(SongQueue *Q);  //updates if song is sung or not
void insertSong(SongBook* A, Discography D); //adds a new song to the song book
void QueueSong(SongQueue *Q, char *IDSong); //inserts a song into the queue

SongStack *History(SongStack *S, SongQueue *Q); //Adds a song to the history if the song has been sung
SongStack *SearchbyArtist(SongBook A, char *IDArt); //displays all songs by the artist
SongStack *SearchbySongLength(SongBook A, Length L); //displays all songs by specified length
SongStack *SearchbyGenre(SongBook A, string genre); //displays all songs by genre;

int main() {

    SongBook A;
    SongQueue Q;
    SongStack S;
    initSongBook(A);
    int x;

    int hashval = (hash("Joji")); 
    // initQueue(Q);
    // initStack(S);

    // Populating List
    Discography D, D1;
    strcpy(D.Artist.ArtistName, "Joji");
    strcpy(D.Artist.ArtistID, "101");
    strcpy(D.Artist.RecordLabel, "88Rising");
    D.Artist.yearBorn = 1990;

    strcpy(D.ArtistSong[0].SongName, "Test Drive");
    strcpy(D.ArtistSong[0].SongID, hashval);
    strcpy(D.ArtistSong[0].genre, "Alternative");
    strcpy(D.ArtistSong[0].ReleaseDate, "2022");
    D.ArtistSong[0].songLength.seconds = 30;
    D.ArtistSong[0].songLength.minutes = 3; 

    strcpy(D.ArtistSong[1].SongName, "Peach Jam");
    strcpy(D.ArtistSong[1].SongID, hashval);
    strcpy(D.ArtistSong[1].genre, "Alternative");
    strcpy(D.ArtistSong[1].ReleaseDate, "2019");
    D.ArtistSong[1].songLength.seconds = 33;
    D.ArtistSong[1].songLength.minutes = 2;  

    insertSong(&A, D);

    // Queueing songs
    // QueueSong(&Q, "SongID1");
    // QueueSong(&Q, "SongID2");
    // // Checking if songs are sung and updating history
    // if (isDone(&Q)) {
    //     History(&S, &Q);
    // }
    // // Searching songs by artist, song length, and genre
    // SearchbyArtist(A, "ArtistID1");
    // Length searchLength = {3, 30};
    // SearchbySongLength(A, searchLength);
    // SearchbyGenre(A, "Genre1");

    // // Displaying the songbook and queue
    displaySongs(A);
    // displayQueue(Q);
    return 0;

}

void initSongBook(SongBook A){

    int x; 
    
    for(x = 0; x < SIZE; x++){
        A[x] = NULL;
    }
    
}

void displaySongs(SongBook A){

    
}



void insertSong(SongBook* A, Discography D) {
   

}

int hash(char artname[]) {
   

}
