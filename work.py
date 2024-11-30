import os
import sys
text = ['Компьютер',
        'Операционная система',
        'Вход в домен',
        'Первичный адрес IP',
        'Системная плата  ',
        'Тип ЦП',
        'Видеоадаптер',
        'Системная память',
        'SMART-статус']
text_info=[
        '1)',
        '2)',
        '3)',]
INDEX = [2, 5, 7, 6, 4]
INDEX_TO = [7]
text_do = ['Тип BIOS' ]
text_new = ['Домен       ',
            'CPU   ',
            'RAM             ',
            'GPU         ',
            'Материнская плата',
            ]
text_info_mew = [
'Ф.И.О.                         ',
'Телефон                        ',
'Почта                          ',
]
text_all = ['Дисковый накопитель']
#номер вхождения
Z = [0,0,0,0,1,0,0,0,0,0,0,0]
#print("Enter kol-vo file for perser")
#Kol = input()
#print("Enter name file for parser without number")
#file1 =input()
#print("Enter name file for save data")
#file2 =input()
Kol = 1;
file1 = sys.argv[-1];
file2 = file1 + '_';
kol_ = 1
while(kol_ <= int(Kol)):
    try:
        X = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        final_file1 = file1 + str(kol_)
        final_file2 = file2 + str(kol_)
        final_file1 = '{}.txt'.format(final_file1 )
        final_file2 = '{}.txt'.format(final_file2)
        f = open(final_file1, "r")
        w = open(final_file2, "a+")
        #f = open( "test1.txt", "r")
        #w = open("test5.txt", "a+")
        Enter_ = 0
        Enter_2 = 1
        Info = 0
        q = 0
        for line in f:
            if (Info == 0 and q < 3):
                if (text_info[q] in line):
                    new_line = line.replace(text_info[q], text_info_mew[q])
                    line = new_line
                    #print(line.lstrip())
                    w.write(line.lstrip())
                else:
                    Info = Info + 1
                q = q + 1
            m = 0
            while m < len(text_all):
                if (text_all[m] in line):
                    if ("00  00  00" in line):
                        KATY = "GENIOR PROGER!"
                    else:
                        #print(line.lstrip())
                        w.write(line.lstrip())
                m = m + 1
            i = 0
            s = 0
            if (Enter_):
                if (text_do[Enter_2] in line):
                    Enter_ = 0
                else:
                    #print(line.lstrip())
                    w.write(line.lstrip())
            else:
                while i < len(text):
                    if (line.find(text[i]) != -1 ):
                        if (X[i] == Z[i]):
                            j = 0
                            while j< len(text_new):
                                if (INDEX[j] == i):
                                    new_line = line.replace(text[i],text_new[j])
                                    line = new_line
                                j = j + 1
                            j = 0
                            while j< len(INDEX_TO):
                                if (INDEX_TO[j] == i):
                                    Enter_ = 1
                                    Enter_2 = j
                                j = j + 1
                            #print(line.lstrip())
                            w.write(line.lstrip())
                        X[i] = X[i] + 1
                    i = i + 1
        f.close()
    except FileNotFoundError:
        print('Файл не существует!')
    kol_ = kol_ + 1


