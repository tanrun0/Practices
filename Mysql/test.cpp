#include <mysql/mysql.h>
#include <iostream>

int main()
{
    // printf("mysql client Version: %s\n", mysql_get_client_info());

    MYSQL *my = mysql_init(nullptr);
    mysql_real_connect(my, LOCAL_HOST, "tr", "123456", "test1", 3306, nullptr, 0);

    mysql_set_character_set(my, "utf8");

    std::cout << "---------插入数据前查询---------" << std::endl;
    mysql_query(my, "select * from stu");    // 这里的sql 可以不带 ;号 (懒得做返回值判断了)
    MYSQL_RES *res = mysql_store_result(my); // 获得完整的查询结果

    // 获得结果的行列数信息
    unsigned int r = mysql_num_rows(res);
    unsigned int c = mysql_num_fields(res);
    std::cout << "结果有: " << r << " 行 " << c << " 列" << std::endl;
    MYSQL_FIELD *my_fd = mysql_fetch_fields(res);

    // 打印表头
    for (int i = 0; i < c; i++)
        std::cout << my_fd[i].name << " "; // 获取每一列的列名
    std::cout << std::endl;

    // 读取每一行结果
    MYSQL_ROW row;
    while (row = mysql_fetch_row(res))
    {
        for (unsigned int i = 0; i < c; i++)
            std::cout << (row[i] ? row[i] : "NULL") << " ";
        std::cout << std::endl;
    }

    mysql_free_result(res);
    std::cout << "------------修改数据-----------" << std::endl;
    mysql_query(my, "insert into stu values(7, 'Yao', 99, 99, 99)");
    mysql_query(my, "insert into stu values(8, 'Curry', 88, 88, 88)");
    // mysql_query(my, "delete stu where name='Tom'"); 如果写错了, 就不会被执行
    mysql_query(my, "delete from stu where name='Tom'");

    std::cout << "---------插入数据后查询---------" << std::endl;
    mysql_query(my, "select * from stu");
    MYSQL_RES *res2 = mysql_store_result(my);
    unsigned int r2 = mysql_num_rows(res2);
    unsigned int c2 = mysql_num_fields(res2);

    MYSQL_FIELD *my_fd2 = mysql_fetch_fields(res2);
    for (int i = 0; i < c2; i++)
        std::cout << my_fd2[i].name << " "; // 获取每一列的列名
    std::cout << std::endl;

    MYSQL_ROW row2;
    while (row2 = mysql_fetch_row(res2))
    {
        for (int i = 0; i < c2; i++)
            std::cout << (row2[i] ? row2[i] : "NULL") << " ";
        std::cout << std::endl;
    }
    mysql_free_result(res2);
    mysql_close(my);
    return 0;
}
