#Rna
<br>
Реализация класса для работы с РНК. Нуклеотиды хранятся побитого, то есть по 4 нуклеотда в одном char'e. Доступ происходит через оператор индексирования.

Перегруженные операторы и методы:

RNA a, b;

a = b               // Присваивание
a + b               // Сложение
a == b              // Сравнение
!a                  // Отрицание (Противоположная цепочка)
a[2] = b[1]         // Индексирование

a.split(3)          // Разделение цепочки относительно идекса
a.isComplemetary()  // Проверка на комплементаронсть