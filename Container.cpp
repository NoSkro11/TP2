#include "Container.h"

Container::Container()
{
    try {
        recovery();
        allSort();
    }
    catch (const char* exception) {
        std::cout << exception;

    }
    catch (const int exceptions) {
        if (exceptions == 1)
            std::cout << "bad index\n";
    }
    
}

void Container::parse(std::string _line,int& _num,std::string& _name,std::string& _time)
{
    std::string num = "";
    std::string name = "";
    std::string time = "";
    
    int i = 0;
    int zpt = 0;
    while (_line[i] != '\n') {
        
        if (_line[i] == ',')
            zpt++;
        else if (zpt == 0)
            num.push_back(_line[i]);
        else if (zpt == 1)
            name.push_back(_line[i]);
        else if (zpt == 2&& _line[i] != ';')
            time.push_back(_line[i]);
        else if (_line[i] == ';')
            break;
        i++;
    
    }
    _num = stoi(num);
    _name = name;
    _time = time;


}

void Container::sort(std::string* arr,int size)
{
    if (size != 0) {
        int i = 0;
        int j = size - 1;

        //Центральный элемент массива
        std::string mid = arr[size / 2];

        //Делим массив
        do {
            //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
            //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
            while (arr[i] < mid) {
                i++;
            }
            //В правой части пропускаем элементы, которые больше центрального
            while (arr[j] > mid) {
                j--;
            }

            //Меняем элементы местами
            if (i <= j) {
                std::string tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                i++;
                j--;
            }
        } while (i <= j);


        //Рекурсивные вызовы, если осталось, что сортировать
        if (j > 0) {
            //"Левый кусок"
            sort(arr, j + 1);
        }
        if (i < size) {
            //"Првый кусок"
            sort(&arr[i], size - i);
        }
    }
    else
        throw "empty list";
}

void Container::find()
{

    std::string h = "", m = "", time = "";
    std::cout << "Enter time\n";

    std::cout << "Enter hours\n";
    std::cin >> h;

    std::cout << "Enter minutes\n";
    std::cin >> m;

    time = h + ":" + m;
    int s = 0;
    for (int i = 0; i < trains.getSize(); i++) {
        
        if (trains[i].getTime() > time) {
            cout << trains[i];
            s++;
        }
       
    }
    if (s == 0) {
        cout << "oops... You are late on all trains\n";

    }

}

void Container::addTr()
{
 
    int num;
    std::string name = "";
    std::string time = "";
    std::string h = "", m = "";

    std::cout << "enter number: ";
    std::cin >> num;

    std::cout << "enter city name: ";
    std::cin >> name;

    std::cout << "enter hours: ";
    std::cin >> h;

    std::cout << "enter minutes: ";
    std::cin >> m;
    time = h + ":" + m;

    trains.append(TRAIN(num, name, time));
    allSort();
    save();
}

void Container::delTr()
{
    
    int n;
    cout << "Now trains: "<<trains.getSize()<<"\nEnter deleted index: ";
    
    std::cin >> n;
    trains.irase(n);
    allSort();
    save();
}

void Container::save()
{
    std::ofstream outs("trains.txt");
    outs.close();
    std::ofstream out("trains.txt", std::ios::app);
    std::string data = "";
    for (int i = 0; i < trains.getSize(); i++) 
        out << trains[i].getNumber() << "," << trains[i].getName() << "," << trains[i].getTime() << ";" << std::endl;
    out.close();

    
}

void Container::recovery()
{
    std::string line;
    std::ifstream f;
    f.open("trains.txt");

    if (f.is_open())
    {
        if (f.peek() == EOF)
        {
            f.close();
            std::cout<<"file is empty\n";

        }
        else {
            while (getline(f, line))
            {

                int num = 0;
                std::string name = "";
                std::string time = "";
                parse(line, num, name, time);

                trains.append(TRAIN(num, name, time));

            }
            f.close();
            std::cout << "Good loads\n";
        }
    }
    else {
        //первый запуск
        init();
        f.open("trains.txt");
        while (getline(f, line))
        {

            int num = 0;
            std::string name = "";
            std::string time = "";
            parse(line, num, name, time);

            trains.append(TRAIN(num, name, time));

        }
        f.close();
        std::cout << "Good loads\n";

    }
}

void Container::change()
{
    int n,num;
    cout << "Now trains: " << trains.getSize() << "\nEnter changed index: ";
    std::cin >> n;

    std::string name = "";
    std::string time = "";
    std::string h = "", m = "";

    std::cout << "enter number: ";
    std::cin >> num;

    std::cout << "enter city name: ";
    std::cin >> name;

    std::cout << "enter hours: ";
    std::cin >> h;

    std::cout << "enter minutes: ";
    std::cin >> m;
    time = h + ":" + m;

    trains[n].setName(name);
    trains[n].setNumber(num);
    trains[n].setTime(time);

    allSort();
    save();
    

}

void Container::show()
{
    std::cout << trains;
}

void Container::allSort()
{
    if (trains.getSize() != 0) {
        std::string* arrT = new std::string[trains.getSize()];
        for (int i = 0; i < trains.getSize(); i++)
            arrT[i] = trains[i].getName();

        std::string nm = "";
        sort(arrT, trains.getSize());
        List<TRAIN> buf;
        for (int i = 0; i < trains.getSize(); i++) {
            for (int j = 0; j < trains.getSize(); j++) {
                nm = trains[j].getName();

                if (nm == arrT[i]) {
                    buf.append(trains[j]);
                    break;
                }
            }

        }
        trains = buf;

        std::cout << trains;
        delete[] arrT;
    }
    else
        throw "empty list\n";
}

void Container::init()
{
    //первый запуск
    std::cout << "file wasn't open because it wasn't created\n";
    std::ofstream out("trains.txt", std::ios::app);

    if (out.is_open())
    {
        int cnt_tr;
        int num;
        std::string name = "";
        std::string time = "";
        std::string h = "", m = "";

        std::cout << "enter count of trains: ";
        std::cin >> cnt_tr;
        for (int i = 0; i < cnt_tr; i++) {
            std::cout << "enter number: ";
            std::cin >> num;

            std::cout << "enter city name: ";
            std::cin >> name;

            std::cout << "enter hours: ";
            std::cin >> h;

            std::cout << "enter minutes: ";
            std::cin >> m;
            time = h + ":" + m;
            out << num << "," << name << "," << time << ";" << std::endl;
        }
    }




    out.close();


}
