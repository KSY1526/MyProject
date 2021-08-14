#include <iostream>

class ArrayList{
    private:
        int *data;
        size_t length;
        size_t current_size;
        size_t resize_unit;
    public:
        ArrayList(size_t init_size = 10){
            std::cout << "\n<Initialize to: " << init_size << "> \n";
            data = new int[init_size];
            current_size = init_size;
            resize_unit = init_size;
            length = 0;
        }
        ~ArrayList(){
            delete [] data;
        }

        void resize(size_t newsize){
            std::cout << "\n<Initialize to: " << newsize << "> ";
            int *temarray = new int[newsize];
            for (int i = 0; i < length; i++){
                temarray[i] = data[i];
            }
            delete [] data;
            current_size = newsize;
            data = temarray;
        }

        void insert(int pos, int e){
            if(pos >= 0 && pos <= length){
                if(isFull()){
                    resize(current_size + resize_unit);
                }
                for(int i = length; i > pos; i--){
                    data[i] = data[i - 1];
                }
                data[pos] = e;
                length++;
            }
            else {
                std::cout << "삽입 위치가 잘못되었습니다.\n";
            }
        }
        
        void remove(int pos){
            if(!isEmpty() && pos >= 0 && pos < length){
                if(current_size > resize_unit + length){
                    resize(current_size - resize_unit);
                }
                for(int i = pos + 1; i < length; i++){
                    data[i-1] = data[i];
                }
                length--;
            }
            else {
                std::cout << "공백상태 또는 삭제 위치가 잘못되었습니다.\n";
            }
        }

        int getEntry(int pos){
            return data[pos];
        }

        bool isEmpty(){
            return length == 0;
        }

        bool isFull(){
            return length == current_size;
        }

        bool find(int item){
            for(int i = 0; i < length; i++){
                if(data[i] == item){
                    return true;
                }
            }
            return false; 
        }

        void replace(int pos, int e){
            if(!isEmpty() && pos >= 0 && pos < length){
                data[pos] = e;
            }
            else {
                std::cout << "공백상태 또는 치환 위치가 잘못되었습니다.\n";
            }
        }

        int size(){
            return length;
        }

        void display(){
            std::cout << "Array List의 총 항목수: " << length;
            for(int i = 0; i < length; i++){
                std::cout << " [" << data[i] << "]";
            }
            std::cout << "\n";
        }

        void clear(){
            length = 0;
            resize(resize_unit);
        }
};

int main(){
    ArrayList list (10);
    for(int i = 0; i < 21; i++){
        list.insert(list.size(), i);
        if(i%10 == 9){
            list.display();
        }
    }

    for(int i = 0; i < 20; i++){
        list.remove(list.size() -1);
        if(i%10 == 9){
            list.display();
        }
    }
    return 0;
}