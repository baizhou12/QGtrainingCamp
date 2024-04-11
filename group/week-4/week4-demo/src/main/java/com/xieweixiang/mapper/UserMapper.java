package com.xieweixiang.mapper;

import com.xieweixiang.pojo.User;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

public interface UserMapper {

    @Select("select * from users")
    List<User> selectAll();

    @Insert("insert into users values(null,#{username},#{password})")
    void add(User user);

    @Select("select * from users where username = #{username}")
    User selectByUsername(String username);

    @Select("select * from users where username=#{username} and password=#{password}")
    User selectUser(@Param("username") String username, @Param("password") String password);
}
