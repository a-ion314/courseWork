#include<iostream>
#include<string>

struct Node{
  std::string name;
  int start;
  int size;
  Node *next = NULL;
};

void mem_init(int memory, struct Node *head){
  head -> next = new Node;
  head -> next -> name = "Empty";
  head -> next -> start = 0;
  head -> next -> size = memory;
}

int mem_add(std::string process_name, struct Node *head, int memsize){
    struct Node *temp, *empty, *del;
	temp = head;
    int counter = 0;
    while((temp -> next) != NULL){
      if (temp-> next-> name == "Empty"){
        if (temp-> next -> size < memsize){
          return -1;
        }
        else if (temp -> next -> size == memsize){
          temp -> next -> name = process_name;
          break;
        }
        else{
          empty = temp -> next;
          empty -> size -= memsize;
          empty -> start += memsize;
          temp -> next = new Node;
          temp -> next -> next = empty;
          temp -> next -> start = counter;
          temp -> next -> size = memsize;
          temp -> next -> name = process_name;
          break;
        }
      }
      counter = counter + (temp -> next -> size);
      temp = temp -> next;
    }
    return 1;
}

void print(struct Node *head){
  struct Node *temp;
  temp = head;
  while ((temp -> next) != NULL){
    std::cout << " -> " <<(temp -> next -> name) << " " << (temp -> next -> start) << " " << (temp -> next -> size) ;
    temp = temp -> next;
  }
  std::cout << std::endl;
}

int mem_del(std::string process_name, struct Node *head){
  struct Node *temp;
  temp = head;
  while((temp -> next) != NULL){
    if (temp -> next -> name == process_name){
      temp -> next -> name = "Empty";
      return 1;
    }
    temp = temp -> next;
  }
  return -1;
}

void merge(struct Node *head){
  struct Node *prev, *after;
  prev = head;
  after = head -> next;
  while (after != NULL){
    if ((prev -> name == "Empty") && (after -> name == "Empty")){
      prev -> size += after -> size;
      prev -> next = after -> next;
      after -> next = NULL;
      delete after;
      break;
    }
    after = after -> next;
    prev = prev -> next;
  }
}

int main(){
  int memory;
  std::cout << "Please input amount of memory units: ";
  std::cin >> memory;
  struct Node *head = new Node;
  head->size = 0;

  mem_init(memory, head);

  std::string proc_name;
  int flag = 0;

  std::string command;
  while (command != "q"){
    print(head);
    std::cout << "a : add process" <<std::endl;
    std::cout << "d : delete process" <<std::endl;
    std::cout << "q : quit" <<std::endl;
    std::cout << "command: ";
    std::cin >> command;
    if (command == "a"){
      print(head);
      std::cout << "Enter process name to add: ";
      std::cin >> proc_name;
      std::cout << "Enter amount of memory units process will take: ";
      std::cin >> memory;
      flag = mem_add(proc_name, head, memory);
      if (flag == -1){
        std::cout << "Could not add process." << std::endl;
      }
    }
    else if (command == "d"){
      std::cout << "Enter process name to delete: ";
      std::cin >> proc_name;
      flag = mem_del(proc_name, head);
      if (flag == -1){
        std::cout << "could not delete process" << std::endl;
      }
      merge(head);
    }
    else if (command == "q"){
      break;
    }
    else
      std::cout << "Command not found." << std::endl;
  }


  return 0;
}
