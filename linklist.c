/* Using the abstract data type “Linked List”, you will create a playlist that
only needs to move 1 direction. The program must allow for the following
● Add songs to the linked list
● Remove songs from the playlist
● Songs contain an artist, name and year released
In main function, simply call the add to playlist 3 times. Print the playlist.
Then call delete on one of the songs and reprint the playlist showing it no
longer contains the delete song. */

#include <stdio.h>
#include <stdlib.h>

struct Song {
    char artist[100];
    char name[100];
    int year;
    struct Song* next;
};

int main(struct Song** head, const char* artist, const char* name, int year) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    if (!newSong) {
        return -1; 
    }
    strncpy(newSong->artist, artist, sizeof(newSong->artist) - 1);
    strncpy(newSong->name, name, sizeof(newSong->name) - 1);
    newSong->year = year;
    newSong->next = *head;
    *head = newSong;
    return 0; 
}
