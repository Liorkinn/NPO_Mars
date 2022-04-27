# Ведение базы данных
ERD диаграмма базы данных, где таблица Gender - "Словарь пола", Education - "Словарь вида образования", Staff - основная таблица с людьми.


![image](https://sun9-86.userapi.com/s/v1/ig2/tk3y0qY4nLFgAQ1XOPAMmr-sJ-SybmEz5Aj8wYxj3XV9xYs7DA72_0_NRe2wVscd1N09asWUfk9gPC6HF2w1zZ86.jpg?size=530x509&quality=96&type=album)

## Использованные инструменты для разработки:

1. Qt
2. PostgreSQL
3. Среда - Ubuntu 20.04


# Заполненная бд(данные в TableView выводятся из БД)
![image](https://sun9-71.userapi.com/s/v1/ig2/nWx87Hi1NDoCp6VD7uBlu15kXf-Gg5CLYufTHtPjhr7VzNhh2V7RsMSrkZvgfgvgUB8teezbUNfrsUKt7BFwnYGY.jpg?size=799x556&quality=96&type=album?)

## Разработанные запросы по заданию:
1. Количество мужчин, старше 30 лет, не имеющих высшее образование

SELECT count(*) FROM "Staff".birth < CURRENT_DATE - interval '30 years'







2. Вывести ФИО, дата рождения, пол у людей, у которых день рождения в ближайшие 10 дней


-SELECT "Staff".name, "Staff".surname, "Staff".patronymic, "Staff".birth, "Gender".gender
FROM "Staff"
JOIN "Gender" ON "Gender".id = "Staff".gender_id
WHERE date_part('year', CURRENT_DATE) = date_part('year', CURRENT_DATE + interval '10days')
   AND date_part('doy', birth)
       BETWEEN date_part('doy', CURRENT_DATE) AND date_part('doy', CURRENT_DATE + interval '10days')
       
 # CREATE scripts для таблиц находится в DBscripts.txt

