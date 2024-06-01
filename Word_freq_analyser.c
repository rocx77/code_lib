#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


// a linked list to store letters of text as its node

typedef struct llnode{
    char letter;
    struct llnode* next;
}ll;



// bst for storing wods of 

typedef struct bst{
    char* data;
    int freq;
    struct bst *left,*right;
}node;



// function to remove all uppercase and special charecters and store in a linked list

struct llnode* rmv(FILE* tx){

    struct llnode* head = NULL;
    struct llnode* curr;


    int pax=0;
    while(1){

        char baba = fgetc(tx);

        if(baba == EOF){
            break;
        }

        pax = 1;

        baba = tolower(baba);

        if(!(baba>='a' && baba<='z')){
            pax++;
            baba = '\n';
        }


        struct llnode* temp = (struct llnode* )malloc(sizeof(struct llnode));

        temp->letter = baba;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }

        else{
            curr->next = temp;
        }

        curr = temp;

    }

    if(pax == 1){
        printf("\nThere is only one word in the text.\n");
    }
    // if(pax == 0){
    //     printf("\nNo word in the text file.");
    // }
    return head;

}







// function to insert in BST and update frequency of a key.

node* insert(node** boot,char* key){

    node* node_p = *boot;
     
    if(node_p == NULL){

        node* temp = (node*)malloc(sizeof(node));
        temp->data = key;
        temp->left = temp->right = NULL;
        temp->freq = 1;

        if(*boot == NULL)
        {
            *boot = temp;
        }
        return temp;
    }

    if(strcmp(key,node_p->data) > 0){
        node_p->right = insert(&node_p->right,key); 
    }
    else if(strcmp(key,node_p->data) < 0){
        node_p->left = insert(&node_p->left,key);
    }
    else if(strcmp(key,node_p->data) == 0){
        node_p->freq++;
    }
        return node_p;
}



// function to search for a key

node* search(node* root, char* word)
{

    if(root == NULL || strcmp(word,root->data) == 0){
        return root;
    }
    else if(strcmp(word,root->data) > 0){
        return search(root->right , word);
    }
    else if(strcmp(word,root->data)<0){
        return search(root->left , word);
    }
    return NULL;

}






int main(){

    // opening the text file.
    FILE* tx = fopen("text.txt","r");


    if(tx == NULL){
        printf("File is not open Exiting program.");
        exit(0);
    }


    //creating the linked list of letters
    struct llnode* head;
    head = rmv(tx);

    if(head == NULL){                             // yaha agar file empty hoga to 
        printf("Text file is empty\n");          //head me koi node add nahi hoga
        exit(0);                                //or head NULL hoga
    }


    ll *tempo = head;

    //cre4ating the BST of keys
    node *root = NULL , *curr = NULL ;

    char *key;



    while(tempo != NULL){

        int i=0;
        char *buff = (char*)malloc(50*sizeof(char));


        while((tempo->letter != ' ') && (tempo->letter != '\n')&& (tempo->letter != EOF)){

            buff[i] = tempo->letter;
            i++;
            tempo = tempo->next;
            if(tempo == NULL){
                break;
            }
        }


        
        buff[i] = '\0';



        key = (char*)malloc(i+1);

        strcpy(key,buff);

        free(buff);

        curr = insert(&root,key);


        if(tempo == NULL){
                    break;
        }

        tempo = tempo->next;

    }

   



    while(1){


            char buffer[101];
            printf("\nEnter the word you want to search : \n");
            scanf(" %100[^\n]", buffer);

            char* word = (char *) malloc(strlen(buffer) + 1);
            strcpy(word, buffer);


            curr = search(root,word);

            free(word);

            if(curr == NULL){
                printf("\nword is not present in the text. Please Try again\n");
            }
            else{
                printf("\nFrequency of the word is %d\n" , curr->freq);
            }

            printf("\nEnter '7' to continue and '9' to exit.\n" ); 
            int x;
            scanf("%d",&x);

            if(x == 9){
                printf("Now exiting the program.");
                exit(0);
            }

    }


}
