#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <limits>
#include <algorithm>

int inp(int a, int b) {
    int n;
    while (true){
        if (!(std::cin >> n) or n < a or n > b) {
            std::cout << "Неверный ввод! Попробуйте ещё раз" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            return n;
        }
    }
}
std::string compareStr(std::string a, std::string b){
    std::string c = "";
    for(char i: a) {
        for (int j = 0 ; j < b.size(); j++) {
            if (b[j] == i) {
                b[j] = 0;
                break;
            }
        }
    }
    for(char i: b){
        if (i != 0){
            c += i;
        }
    }
    return c;
}
std::string giveSubstr(std::string s, int a) {
    std::string str = "";
    for (int i = 0; i < a; i++) {
        str += s[i];
    }
    return str;
}
std::string giveSubstr(std::string s, int a, int b) {
    std::string str = "";
    for (int i = a; i <= b; i++) {
        str += s[i];
    }
    return str;
}
int stringSum(std::string s){
    int c = 0;
    for(int i = 0; i < s.size(); i++){
        c += std::stoi(giveSubstr(s, i, i));
    }
    return c;
}
class Combo{
    int val, num;
    bool taken;
    std::string name;
public:
    std::string checkConditions(int dice[], std::string *toRoll){
        std::string dc = "", wrongs = "", s = "", st = "";
        int num = 5;
        for (int i = 0; i < 5; i++){
            dc += std::to_string(dice[i]);
        }
        switch (this->num) {
            case 6:
                for(int i = 1; i <= 6; i++){
                    s = std::to_string(i)+std::to_string(i);
                    st = compareStr(s, dc);
                    if(st.size() <= num){
                        wrongs = st;
                        *toRoll = st;
                        num = st.size();
                    }
                }
                break;
            case 7:
                for(int i = 1; i <= 5; i++){
                    for(int j = i+1; j <= 6; j++){
                        s = std::to_string(i)+std::to_string(i)+std::to_string(j)+std::to_string(j);
                        st = compareStr(s, dc);
                        if(st.size() <= num){
                            wrongs = st;
                            *toRoll = st;
                            num = st.size();
                        }
                    }
                }
                break;
            case 8:
                for(int i = 1; i <= 6; i++){
                    s = std::to_string(i)+std::to_string(i)+std::to_string(i);
                    st = compareStr(s, dc);
                    if(st.size() <= num){
                        wrongs = st;
                        *toRoll = st;
                        num = st.size();
                    }
                }
                break;
            case 9:
                for(int i = 0; i <= 2; i++) {
                    s = "";
                    for (int j = 1 + i; j <= 4 + i; j++) {
                        s += std::to_string(j);
                    }
                    st = compareStr(s, dc);
                    if(st.size() <= num){
                        wrongs = st;
                        *toRoll = st;
                        num = st.size();
                    }
                }
                break;
            case 10:
                for(int i = 0; i <= 2; i++) {
                    s = "";
                    for (int j = 1 + i; j <= 5 + i; j++) {
                        s += std::to_string(j);
                    }
                    st = compareStr(s, dc);
                    if(st.size() <= num){
                        wrongs = st;
                        *toRoll = st;
                        num = st.size();
                    }
                }
                break;
            case 11:
                for(int g = 0; g < 2; g++){
                    for(int i = 1; i <= 5; i++){
                        for(int j = i+1; j <= 6; j++){
                            s = "";
                            for(int k = 0; k < 3-g; k++){
                                s += std::to_string(i);
                            }
                            for(int k = 0; k < 2+g; k++){
                                s += std::to_string(j);
                            }
                            st = compareStr(s, dc);
                            if(st.size() <= num){
                                wrongs = st;
                                *toRoll = st;
                                num = st.size();
                            }
                        }
                    }
                }
                break;
            case 12:
                for(int i = 1; i <= 6; i++){
                    s = std::to_string(i)+std::to_string(i)+std::to_string(i)+std::to_string(i);
                    st = compareStr(s, dc);
                    if(st.size() <= num){
                        wrongs = st;
                        *toRoll = st;
                        num = st.size();
                    }
                }
                break;
            case 13:
                for(int i = 1; i <= 6; i++){
                    s = std::to_string(i)+std::to_string(i)+std::to_string(i)+std::to_string(i)+std::to_string(i);
                    st = compareStr(s, dc);
                    if(st.size() <= num){
                        wrongs = st;
                        *toRoll = st;
                        num = st.size();
                    }
                }
                break;
            case 14:
                s = "66666";
                wrongs = compareStr(s, dc);
                *toRoll = wrongs;
                break;
        }
        wrongs = giveSubstr(wrongs, s.size()-(5-wrongs.size()));
        return wrongs;
    }
    bool isTaken(){
        return this->taken;
    }
    std::string getname(){
        return this->name;
    }
    int getVal(){
        return this->val;
    }
    void setTaken(int v){
        this->taken = true;
        this->val = v;
    }
    Combo(int i){
        this->val = 0;
        this->num = i;
        this->taken = false;
        switch (i) {
            case 0:
                this->name = "Единицы";
                break;
            case 1:
                this->name = "Двойки";
                break;
            case 2:
                this->name = "Тройки";
                break;
            case 3:
                this->name = "Четвёрки";
                break;
            case 4:
                this->name = "Пятёрки";
                break;
            case 5:
                this->name = "Шестёрки";
                break;
            case 6:
                this->name = "Пара";
                break;
            case 7:
                this->name = "Две пары";
                break;
            case 8:
                this->name = "Тройка";
                break;
            case 9:
                this->name = "Малый стрит";
                break;
            case 10:
                this->name = "Большой стрит";
                break;
            case 11:
                this->name = "Фул хаус";
                break;
            case 12:
                this->name = "Каре";
                break;
            case 13:
                this->name = "Покер";
                break;
            case 14:
                this->name = "Шанс";
                break;
        }
    }
};
class Die{
    int val;
    std::string disp[5];
    std::string d[6][5] = {{" --------- ","|         |","|    *    |","|         |"," --------- "},
                           {" --------- ","|      *  |","|         |","|  *      |"," --------- "},
                           {" --------- ","|      *  |","|    *    |","|  *      |"," --------- "},
                           {" --------- ","|  *   *  |","|         |","|  *   *  |"," --------- "},
                           {" --------- ","|  *   *  |","|    *    |","|  *   *  |"," --------- "},
                           {" --------- ","|  *   *  |","|  *   *  |","|  *   *  |"," --------- "}};
public:
    void gend(){
        int a = rand() % 6 +1;
        this->val = a;
        for (int i = 0; i < 5; i++){
            this->disp[i] = d[a-1][i];
        }
    }
    std::string giveDisp(int a){
        return this->disp[a];
    }
    int getVal(){
        return this->val;
    }
    Die(){
        this->gend();
    }
};
class Player{
    std::vector <Die> arr;
    std::vector <Combo> count;
    bool rolled;
    bool bot;
    bool roll(int dice){
        int r = std::to_string(dice).size();
        bool flag = false;
        for (int i = 0; i < r; i++){
            if (dice%10 > 0 and dice%10 < 7){
                this->arr[dice%10-1].gend();
                flag = true;
            }
            dice /= 10;
        }
        return flag;
    }
    void roll(){
        for (int i = 0; i < 5; i++){
            this->arr[i].gend();
        }
    }
    int find(int num){
        int c = 0;
        for(int i = 0; i < 5; i++){
            if (arr[i].getVal() == num){
                c += 1;
            }
        }
        return c;
    }
    bool makeRolls(){
        std::cout << "Введите номера перебрасываемых кубиков (Например: 123 (переброс первых трёх), 0(переброса не будет))" << std::endl;
        int a = inp(0,99999);
        if (this->roll(a)){
            this->rolled = true;
            this->printDice();
            return true;
        }
        return false;
    }
    void avComb(int a, int b){
        std::cout << "Доступные комбинации:" << std::endl;
        for(int i = a; i <= b; i++){
            if(!this->count[i].isTaken()){
                std::cout << i+1 <<". " << this->count[i].getname() << std::endl;
            }
        }
    }
    void giveArr(int (&a)[5]){
        for (int i = 0; i < 5; i++){
            a[i] = this->arr[i].getVal();
        }
        std::sort(a, a + 5);
    }
    int checkComb(int a) {
        std::string s = "", st = "", dc = "", wrongs, buff;
        int dice[5];
        int sum = 0, num = 5;
        giveArr(dice);
        for (int i = 0; i < 5; i++){
            dc += std::to_string(dice[i]);
        }
        switch (a) {
            case 0:case 1:case 2:case 3:case 4:case 5:
                return (this->find((a + 1)) - 3) * (a + 1);
            case 6:
                if(count[a].checkConditions(dice, &buff).size() == 0){
                    for(int i = 1; i <= 6; i++){
                        s = std::to_string(i)+std::to_string(i);
                        st = compareStr(s, dc);
                        if(st.size() <= num){
                            wrongs = st;
                            num = st.size();
                            if (5-wrongs.size() == s.size()){
                                sum = stringSum(s);
                            }
                        }
                    }
                }
            case 7:
                if(count[a].checkConditions(dice, &buff).size() == 0) {
                    for (int i = 1; i <= 5; i++) {
                        for (int j = i + 1; j <= 6; j++) {
                            s = std::to_string(i) + std::to_string(i) + std::to_string(j) + std::to_string(j);
                            st = compareStr(s, dc);
                            if (st.size() <= num) {
                                wrongs = st;
                                num = st.size();
                                if (5-wrongs.size() == s.size()){
                                    sum = stringSum(s);
                                }
                            }
                        }
                    }
                }
                return sum + sum * !this->rolled;
            case 8:
                if(count[a].checkConditions(dice, &buff).size() == 0) {
                    for (int i = 1; i <= 6; i++) {
                        s = std::to_string(i) + std::to_string(i) + std::to_string(i);
                        st = compareStr(s, dc);
                        if (st.size() <= num) {
                            wrongs = st;
                            num = st.size();
                            if (5-wrongs.size() == s.size()){
                                sum = stringSum(s);
                            }
                        }
                    }
                }
                return sum + sum * !this->rolled;
            case 9:
                if(count[a].checkConditions(dice, &buff).size() == 0) {
                    for (int i = 0; i <= 2; i++) {
                        s = "";
                        for (int j = 1 + i; j <= 4 + i; j++) {
                            s += std::to_string(j);
                        }
                        st = compareStr(s, dc);
                        if (st.size() <= num) {
                            wrongs = st;
                            num = st.size();
                            if (5-wrongs.size() == s.size()){
                                sum = stringSum(s);
                            }
                        }
                    }
                }
                return sum + sum * !this->rolled;
            case 10:
                if(count[a].checkConditions(dice, &buff).size() == 0) {
                    for (int i = 0; i <= 2; i++) {
                        s = "";
                        for (int j = 1 + i; j <= 5 + i; j++) {
                            s += std::to_string(j);
                        }
                        st = compareStr(s, dc);
                        if (st.size() <= num) {
                            wrongs = st;
                            num = st.size();
                            if (5-wrongs.size() == s.size()){
                                sum = stringSum(s);
                            }
                        }
                    }
                }
                return sum + sum * !this->rolled;
            case 11:
                if(count[a].checkConditions(dice, &buff).size() == 0) {
                    for (int g = 0; g < 2; g++) {
                        for (int i = 1; i <= 5; i++) {
                            for (int j = i + 1; j <= 6; j++) {
                                s = "";
                                for (int k = 0; k < 3 - g; k++) {
                                    s += std::to_string(i);
                                }
                                for (int k = 0; k < 2 + g; k++) {
                                    s += std::to_string(j);
                                }
                                st = compareStr(s, dc);
                                if (st.size() <= num) {
                                    wrongs = st;
                                    num = st.size();
                                    if (5-wrongs.size() == s.size()){
                                        sum = stringSum(s);
                                    }
                                }
                            }
                        }
                    }
                }
                return sum + sum * !this->rolled;
            case 12:
                if(count[a].checkConditions(dice, &buff).size() == 0) {
                    for (int i = 1; i <= 6; i++) {
                        s = std::to_string(i) + std::to_string(i) + std::to_string(i) + std::to_string(i);
                        st = compareStr(s, dc);
                        if (st.size() <= num) {
                            wrongs = st;
                            num = st.size();
                            if (5-wrongs.size() == s.size()){
                                sum = stringSum(s);
                            }
                        }
                    }
                }
                return sum + sum * !this->rolled;
            case 13:
                if(count[a].checkConditions(dice, &buff).size() == 0) {
                    for (int i = 1; i <= 6; i++) {
                        s = std::to_string(i) + std::to_string(i) + std::to_string(i) + std::to_string(i) +
                            std::to_string(i);
                        st = compareStr(s, dc);
                        if (st.size() <= num) {
                            wrongs = st;
                            num = st.size();
                            if (5-wrongs.size() == s.size()){
                                sum = stringSum(s);
                            }
                        }
                    }
                }
                return sum + sum * !this->rolled;
            case 14:
                return dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
        }
        return 0;
    }
        bool assign(int a){
        if (!this->count[a].isTaken()){
            std::cout <<"В комбинацию "<< a+1<< "." << this->count[a].getname() << " записано: " << this->checkComb(a) <<std::endl;
            //sleep(3);
            this->count[a].setTaken(this->checkComb(a));
            return true;
        }
        return false;
    }
public:
    int getCount(){
        int sm = 0;
        for(Combo i: this->count){
            sm += i.getVal();
        }
        return sm;
    }
    void printDice() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                std::cout << this->arr[j].giveDisp(i);
            }
            std:: cout << std::endl;
        }
    }
    void rollWrongs(int ind, int dice[]){
        std::string wrongs = "", s = "";
        count[ind].checkConditions(dice, &wrongs);
        bool takenind[5] = {false,false,false,false,false};
        if (wrongs.size()>0){
            for(int i = 0; i < wrongs.size(); i++){
                for(int j = 0; j < this->arr.size(); j++){
                    if(arr[j].getVal() == std::stoi(giveSubstr(wrongs, i, i)) and !takenind[j]){
                        takenind[j] = true;
                        break;
                    }
                }
            }
        }
        for(int g = 0; g < 5; g++){
            if(takenind[g]){
                s += std::to_string(g+1);
            }
        }
        this->roll(stoi(s));
    }
    int findFitting(bool part){
        int nums[6] = {0,0,0,0,0,0};
        int num = 0, ind = -1;
        std::string buff;
        for(int i = 0; i < 6; i++){
            nums[i] = find(i+1);
        }
        if(!part){
            for(int i = 0; i < 6; i++){
                if (!this->count[i].isTaken() and nums[i] >= num){
                    num = nums[i];
                    ind = i;
                }
            }
            for(int i = 0; i < 5; i++){
                if(this->arr[i].getVal() != ind+1){
                    this->arr[i].gend();
                    this->rolled = true;
                }
            }
            for(int i = 0; i < 6; i++){
                if (!this->count[i].isTaken() and nums[i] >= num){
                    num = nums[i];
                    ind = i;
                }
            }
            return ind;
        }else{
            for (int i = 6; i < 14; i++){
                if (!this->count[i].isTaken() and this->checkComb(i) >= num){
                    num = this->checkComb(i);
                    ind = i;
                }
            }
            if (num > 0){
                return ind;
            }else{
                num = 100;
                ind = -1;
                int dice[5];
                giveArr(dice);
                for (int i = 6; i < 15; i++){
                    if (!this->count[i].isTaken()){
                        if(count[i].checkConditions(dice, &buff).size() <= num){
                            num = count[i].checkConditions(dice, &buff).size();
                            ind = i;
                        }
                    }
                }
                this->rolled = true;
                this->rollWrongs(ind, dice);
                num = 0;
                for (int i = 13; i >= 6; i--){
                    if (!this->count[i].isTaken() and this->checkComb(i) > num){
                        ind = i;
                        num = this->checkComb(i);
                    }
                }
                return ind;
            }
        }
    }
    void makeTurn(int part){
        this->rolled = false;
        this->roll();
        this->printDice();
        int a;
        if (this->bot){
            if(!part){
                for (int i = 0; i < 2; i++){
                    a = this->findFitting(part)+1;
                    this->printDice();
                }
            }else{
                for (int i = 0; i < 2; i++){
                    a = this->findFitting(part)+1;
                    this->printDice();
                }
            }
            this->avComb(0+6*part,5+9*part);
            this->assign(a-1);
        }else{
            this->avComb(0+6*part,5+9*part);
            for(int i = 0; i < 2; i++){
                if (this->makeRolls()){
                    this->avComb(0+6*part,5+9*part);
                }
            }
            std::cout << "Запись в комибинацию номер:" << std::endl;
            while (true){
                int a = inp(1+6*part,6+9*part);
                if (this->assign(a-1)){
                    break;
                }
                std::cout << "Комбинация занята" << std::endl;
            }
        }
    }
    Player(bool isBot){
        this->bot = !isBot;
        for(int i = 0; i < 5; i++){
            Die *a = new Die;
            this->arr.push_back(*a);
        }
        for (int i = 0; i < 15; i++){
            Combo *a = new Combo(i);
            this->count.push_back(*a);
        }
    }
};

int main() {
    setlocale(0, "");
    srand(time(0));
    std::vector <Player> playrs;
    std::cout << "Введите количество игроков [2,4]" << std::endl;
    int r = inp(2,4);
    for (int i = 0; i < r; i++){
        std::cout << "Игрок " << i+1 <<" является человеком? (1 - да, 0 - нет)" << std::endl;
        Player *a = new Player(inp(0,1));
        playrs.push_back(*a);
    }
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < r; j++){
            std::cout << "Ход игрока " << j+1  << std::endl;
            playrs[j].makeTurn(0);
        }
    }

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < r; j++){
            std::cout << "Ход игрока " << j+1  << std::endl;
            playrs[j].makeTurn(1);
        }
    }

    for (int i = 0; i < r; i++){
        std::cout << "Счёт игрока игрока " << i+1 << ": " << playrs[i].getCount() << std::endl;
    }
    playrs.clear();

    return 0;
}
