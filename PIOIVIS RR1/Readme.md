# Рассчетная работа №1
Вариант 1.20, способ выражения графа - список инцидентности.

Постановка задачи: Проверить является ли граф графом Паппа.

# Список используемых понятий
- Граф - математическая абстракция реальной системы любой природы, объекты которой обладают парными связями. Граф как математический объект есть совокупность двух множеств — множества самих объектов, называемого множеством вершин, и множества их парных связей, называемого множеством рёбер. Элемент множества рёбер есть пара элементов множества вершин.

- Неориентированный граф - это граф, в котором узлы не имеют направления.

- Графом Паппа - двудольный 3-регулярный неориентированный граф с 18 вершинами и 27 рёбрами.

- Петля - ребро, инцидентное одной и той же вершине

- Кратные рёбра - это два и более рёбер, инцидентных одним и тем же двум вершинам.

- Регулярный граф — граф, степени всех вершин которого равны.

- Степень вершины графа — количество рёбер графа инцидентных вершине.

- Двудоольный граф — это граф, множество вершин которого можно разбить на две части таким образом, что каждое ребро графа соединяет вершину из одной части с какой-то вершиной другой части, то есть не существует рёбер между вершинами одной и той же части графа. 

# Описание алгоритма

1. Программа считывает содержимое выбранного файла и заносит его в двумерный вектор(в виде списка инцидентности).

2. Программа конвертирует список инцидентности в список смежности.

3. Происходит проверка на количество вершин графа. Если их не 18, то в консоль выводится "It isn't Pappus graph" и выполнение программы завершается.

4. Для каждой вершины проверяется количество смежных вершин. Если из не 3, то в консоль выводится "It isn't Pappus graph" и выполнение программы завершается.

5. Проверяется наличие петель. Если хоть одна вершина смежна самой себе, то в консоль выводится "It isn't Pappus graph" и выполнение программы завершается.

6. Выполняется проверка на двудольность. С помощью поиска в глубину программа проходит все вершины графа, устанавливая для каждой вершины условный цвет 0 или 1 в зависимости от того какой цвет был у предыдущей пройденной вершины(если предыдущая была 0, текущая получит 1). Если хоть у одной вершины будет смежная вершина того же цвета, то в консоль выводится "It isn't Pappus graph" и выполнение программы завершается.

7. Если граф прошел все проверки, то в консоль выводится "It is Pappus graph" и выполнение программы завершается.

# Примеры работы
 - graph1.txt
<img width="800" alt="graph1" src="https://github.com/Demeg0r/my_labs/blob/main/PIOIVIS%20RR1/pictures/NotGraphPappa1.jpg">

В консоль выведется: "It isn't Pappus graph".

В первом примере граф не пройдет проверку на количество вершин.

 - graph2.txt
<img width="800" alt="graph2" src="https://github.com/Demeg0r/my_labs/blob/main/PIOIVIS%20RR1/pictures/NotGraphPappa2.jpg">

В консоль выведется: "It isn't Pappus graph".

Во втором примере граф не пройдет проверку на количество вершин смежных для для любой вершины.

- graph3.txt
<img width="800" alt="graph3" src="https://github.com/Demeg0r/my_labs/blob/main/PIOIVIS%20RR1/pictures/NotGraphPappa3.jpg">

В консоль выведется: "It isn't Pappus graph".

Во третьем примере граф не пройдет проверку на двудольность.

 - graph4.txt
<img width="800" alt="graph4" src="https://github.com/Demeg0r/my_labs/blob/main/PIOIVIS%20RR1/pictures/GraphPappa4.jpg">

В консоль выведется: "It is Pappus graph". 

В четвертом примере граф соответствует всем требованиям и пройдет проверку.

- graph5.txt
<img width="800" alt="graph5" src="https://github.com/Demeg0r/my_labs/blob/main/PIOIVIS%20RR1/pictures/GraphPappa5.jpg">

В консоль выведется: "It is Pappus graph". 

В пятом примере граф соответствует всем требованиям и пройдет проверку.

# Вывод

Благодаря данной расчетной работе я освоил базовые знания о теории графов, научился пользоваться некоторыми алгоритмами для работы с графами, узнал о разных формах представления графов.

# Источники

- https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjjzMW3kZH8AhU49LsIHUhUA14QFnoECAoQAQ&url=https%3A%2F%2Fru.wikipedia.org%2Fwiki%2F%25D0%2593%25D1%2580%25D0%25B0%25D1%2584_(%25D0%25BC%25D0%25B0%25D1%2582%25D0%25B5%25D0%25BC%25D0%25B0%25D1%2582%25D0%25B8%25D0%25BA%25D0%25B0)&usg=AOvVaw0mHoGe4GSTNWCXXUJ1WysJ
- https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjT5-nLkZH8AhUPh_0HHSMnCOQQFnoECBQQAw&url=https%3A%2F%2Fru.wikipedia.org%2Fwiki%2F%25D0%259F%25D0%25B5%25D1%2582%25D0%25BB%25D1%258F_(%25D1%2582%25D0%25B5%25D0%25BE%25D1%2580%25D0%25B8%25D1%258F_%25D0%25B3%25D1%2580%25D0%25B0%25D1%2584%25D0%25BE%25D0%25B2)&usg=AOvVaw12_d_k94_4827CXNYb8uhE
- https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwi0-4yag5H8AhXci_0HHafhAGgQFnoECA0QAQ&url=https%3A%2F%2Fru.wikipedia.org%2Fwiki%2F%25D0%2594%25D0%25B2%25D1%2583%25D0%25B4%25D0%25BE%25D0%25BB%25D1%258C%25D0%25BD%25D1%258B%25D0%25B9_%25D0%25B3%25D1%2580%25D0%25B0%25D1%2584&usg=AOvVaw21_UuqJ_0w5FDaI9LqXQG9
- https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwit56Clg5H8AhUa_rsIHaaICWwQFnoECAwQAQ&url=https%3A%2F%2Fru.wikipedia.org%2Fwiki%2F%25D0%25A1%25D1%2582%25D0%25B5%25D0%25BF%25D0%25B5%25D0%25BD%25D1%258C_%25D0%25B2%25D0%25B5%25D1%2580%25D1%2588%25D0%25B8%25D0%25BD%25D1%258B_(%25D1%2582%25D0%25B5%25D0%25BE%25D1%2580%25D0%25B8%25D1%258F_%25D0%25B3%25D1%2580%25D0%25B0%25D1%2584%25D0%25BE%25D0%25B2)&usg=AOvVaw1NpZD_Fi6gO8j13olBjkXI
- https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwir1LuohJH8AhVT7rsIHUrRBMoQFnoECA8QAQ&url=https%3A%2F%2Fru.wikipedia.org%2Fwiki%2F%25D0%25A0%25D0%25B5%25D0%25B3%25D1%2583%25D0%25BB%25D1%258F%25D1%2580%25D0%25BD%25D1%258B%25D0%25B9_%25D0%25B3%25D1%2580%25D0%25B0%25D1%2584&usg=AOvVaw1wa69hWjjsLHH1L4IXSaAD
- https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwim4_eqg5H8AhVD_7sIHQWBC50QFnoECBIQAQ&url=https%3A%2F%2Fru.wikipedia.org%2Fwiki%2F%25D0%2593%25D1%2580%25D0%25B0%25D1%2584_%25D0%259F%25D0%25B0%25D0%25BF%25D0%25BF%25D0%25B0&usg=AOvVaw1Ia1jX5-J2_XdBVWwSdl6a
- https://habr.com/ru/company/otus/blog/568026/
- https://habr.com/ru/company/otus/blog/675730/
- https://stackoverflow.com/