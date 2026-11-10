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
#include <string.h>

struct Song {
    char artist[100];
    char name[100];
    int year;
    struct Song* next;
};

void addSong(struct Song** head, const char* artist, const char* name, int year) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    if (newSong == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    strcpy(newSong->artist, artist);
    strcpy(newSong->name, name);
    newSong->year = year;
    newSong->next = NULL;

    if (*head == NULL) {
        *head = newSong;
        return;
    }

    struct Song* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newSong;
}

void removeSong(struct Song** head, const char* name) {
    struct Song* temp = *head;
    struct Song* prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next; 
        free(temp);         
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nSong '%s' not found in the playlist.\n", name);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printPlaylist(struct Song* head) {
    if (head == NULL) {
        printf("The playlist is empty.\n");
        return;
    }

    struct Song* temp = head;
    int trackNum = 1;
    while (temp != NULL) {
        printf("%d. \"%s\" by %s (%d)\n", trackNum, temp->name, temp->artist, temp->year);
        temp = temp->next;
        trackNum++;
    }
}

int main() {
    struct Song* myPlaylist = NULL;

    addSong(&myPlaylist, "The Beatles", "Hey Jude", 1968);
    addSong(&myPlaylist, "Queen", "Bohemian Rhapsody", 1975);
    addSong(&myPlaylist, "Michael Jackson", "Thriller", 1982);

    printf("\nOriginal Playlist\n");
    printPlaylist(myPlaylist);

    printf("\nRemoving 'Bohemian Rhapsody' from the playlist...\n");
    removeSong(&myPlaylist, "Bohemian Rhapsody");

    printf("\nUpdated Playlist\n");
    printPlaylist(myPlaylist);

    struct Song* current = myPlaylist;
    struct Song* nextSong;
    while (current != NULL) {
        nextSong = current->next;
        free(current);
        current = nextSong;
    }

    return 0;
}
