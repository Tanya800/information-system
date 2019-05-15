# Информационно-поисковая система "Музыкальная школа"

Приложение информационно-поисковая система "Музыкальная школа", написанное на C ++, позволяет хранить информацию об учениках определенной музыкальной школы. Приложение обеспечивает стандартные функции систем хранения данных, а также обеспечивает сохранения проекта в текстовой файл.
![alt text](https://github.com/Tanya800/information-system/blob/master/Images/screen.png)

# Функциональность системы

Программа дает возможность выполнять следующие действия: 
- Добавить данные в таблицу;
- Удалить;
- Редактировать данные ученика;
- Поиск в таблице ученика.

Добавление ученика происходит только после того, как вы заполните все поля для ввода данных, если хоть одно окажется пустым, тогда программа укажет вам это.
![alt text](https://github.com/Tanya800/information-system/blob/master/Images/1.png)
После успешного ввода данных, требуется нажать на кнопку "Добавить", ученик отобразиться в таблице и сохранится в программе.
![alt text](https://github.com/Tanya800/information-system/blob/master/Images/2.png)
Удаление информации происходит по индексу. Если вы захотите удалить данные ученика, вам необходимо нажать на определенного ученика в таблице, либо ввести самостоятельно индекс данного ученика в поле для удаления.![alt text](https://github.com/Tanya800/information-system/blob/master/Images/Удалить.png) Затем нужно лишь нажать кнопку "Удалить" и информация в таблице обновится сама.![alt text](https://github.com/Tanya800/information-system/blob/master/Images/Удалить1.png)  
Для редактирования информации нужно выполнить те же самые действия , как и для удаления, только индекс требуется заносить в поле для изменений данных. Затем необходимо нажать кнопку "Изменить". Данные выбранного ученика подсветятся зеленым цветом и в полях для ввода для ввода данных отобразится информация о данном ученике.![alt text](https://github.com/Tanya800/information-system/blob/master/Images/Изменение.png) Вы можете поменять значения, после нажать лишь кнопку "Добавить", или не менять и нажать кнопку "Отмена".![alt text](https://github.com/Tanya800/information-system/blob/master/Images/Изменение1.png)  
Для поиска нужно только ввести информацию, которую вы хотите найти, и нажать кнопку "Поиск"(внимание! учитывается только полное совпадание с введенным словом).(https://github.com/Tanya800/information-system/blob/master/Images/Поиск.png) Перед вами отобразится таблица результата поиска, в которой можно выполнять различные операции.(https://github.com/Tanya800/information-system/blob/master/Images/Поиск1.png) Чтобы вернуть таблицу со всеми данными, нажмите кнопку "Показать информацию".  

# Необходимые условия

Исполняемые файл находится в папке "Release". Чтобы запустить исполняемый файл, нужно загрузить всю папку и запустить файл "Coursework.exe".
Для того , чтобы скопилировать код, вам потребуется:
1. Установить Qt Creator 4.8.1.
2. Скачать все файлы с репозитория.
3. Скомпилировать.
