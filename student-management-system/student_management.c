#include<stdio.h>
#include<string.h>

typedef struct student_management
{
    int id;
    char name[15];
    int marks;
}student;

student students[100];
int count = 0;

void add(){
    if(count>=100){
        printf("Databse full\n");
        return;
    }

    int id;
    printf("Enter student id: ");
    if (scanf("%d", &id) != 1) return;
    for(int i=0;i<count;i++){
        if(students[i].id == id){
            printf("Id alredy exists\n");
            return;
        }
    }
    students[count].id = id;

    getchar(); // consume leftover newline

    printf("Enter student name: ");
    fgets(students[count].name, sizeof(students[count].name), stdin);
    students[count].name[strlen(students[count].name) - 1] = '\0';

    int marks;
    printf("Enter student marks: ");
    if (scanf("%d", &marks) != 1) return;
    if(marks > 100 || marks < 0){
        printf("Invalid input\nEnter marks from 0 to 100\n");
        return;
    }
    students[count].marks = marks;

    printf("Student added\n");

    count++;
}

void search(){
    int id;
    printf("Enter student id: ");
    scanf("%d",&id);
    int found = 0;
    for(int i=0;i<count;i++){
        if(students[i].id == id){
            printf("Id: %d\n",students[i].id);
            printf("Name: %s\n",students[i].name);
            printf("Marks: %d\n",students[i].marks);
            
            found = 1;
            break;
        }
    }

    if(!found) printf("Student not found\n");
}

void display(){
    for(int i=0;i<count;i++){
        printf("Id: %d\n",students[i].id);
        printf("Name: %s\n",students[i].name);
        printf("Marks: %d\n",students[i].marks);
        printf("\n");
    }
}

void delete(){
    int id;
    printf("Enter student id you want to delete: ");
    scanf("%d",&id);
    int index = -1;

    for(int i=0;i<count;i++){
        if(students[i].id == id){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Student not found\n");
        return;
    } 

    for(int i=index;i<count-1;i++){
        students[i] = students[i+1];
    }

    count--;

    printf("Student deleted\n");
}

void showMenu(){
    printf("\n");
    printf("1. Add student\n");
    printf("2. Display all students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("0. Exit\n");
}


int main(){
    int usrInput = -1;
    
    while(usrInput!=0){
        showMenu();
        printf("Choose operation: ");
        scanf("%d",&usrInput);

        switch (usrInput)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            delete();
            break;
        case 0:
            break;
        default:
            printf("Invalid Input");
            break;
        }
    }
    
    return 0;
}

