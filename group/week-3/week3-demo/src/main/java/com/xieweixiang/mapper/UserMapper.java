package com.xieweixiang.mapper;

import com.xieweixiang.pojo.User;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;

import javax.servlet.annotation.WebServlet;
import java.util.List;

public interface UserMapper {

    @Select("select * from tb_user")
    List<User> selectAll();

    @Insert("insert into tb_user values(null,#{username},#{password},#{gender},#{addr})")
    void add(User user);
}
