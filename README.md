# 1C_task

## Task

Реализуйте программу “автодополнение”.  На вход подаются тексты произвольной длины. Затем, по запросу, программа дополняет слово по префиксу. Слово, которое подсказывает программа, должно быть самым популярным среди слов, добавленных ранее. Также можно использовать функцию “дописывание” и дописать несколько символов к уже введённому префиксу получив, возможно, другую подсказку.

Например:
- Добавить текст: “яблоко яблоко яблоневый”
- Запрос: “ябло”
- Подсказка: “яблоко”
- Дописывание: “н” (т.е. весь префикс - “яблон”)
- Подсказка: “яблоневый”
- Добавить текст: “яблоня яблоня яблоня”
- Запрос: “ябл”
- Подсказка: “яблоня”

## Input format

- Добавить текст
```
+ word1 word2 word3
```

- Сделать запрос на автодополнение
```
? word
```

- Сделать дописывание слово к последнему запросу
```
# word
```

- Все запросы в одну строчку

## Usage example

- Собрать проект

```
../1C_task/src$ cmake CMakeLists.txt
../1C_task/src$ make
```

- Запустить тест

```
../1C_task/src$ ./autocompleter <tests/test3.txt
```

## Solution

- Класс `Driver` отвечает за логику фронтенда. Здесь происходит чтение и формирование запроса, а также вывод итогового результата 
- Класс `Parser` разбивает текст на слова. Сюда стоит добавить обработку знаков препинания, а также space-symbols, кроме пробела. 
- Класс `Autocompleter` отвечает за прием запросов к бэкенду и хранение промежуточных состояний.
- Класс `Trie` делает всю работу алгоритмическую работу. По факту это просто бор, в котором храним все слова из всех текстов. При запросе слова достаточно спуститься по бору, а дополнение слова - спуститься по самой частой ветке.