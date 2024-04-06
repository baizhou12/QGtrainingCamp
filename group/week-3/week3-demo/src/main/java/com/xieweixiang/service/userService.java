package com.xieweixiang.service;

import com.xieweixiang.mapper.UserMapper;
import com.xieweixiang.pojo.User;
import com.xieweixiang.util.SqlSessionFactoryutil;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;

import java.util.List;

public class userService {
    SqlSessionFactory factoty = SqlSessionFactoryutil.getSqlSessionFactory();

    public List<User> selectAll() {
        SqlSession sqlSession = factoty.openSession();

        UserMapper mapper = sqlSession.getMapper(UserMapper.class);

        List<User> users = mapper.selectAll();

        sqlSession.close();

        return users;
    }

    public void add(User user) {
        SqlSession sqlSession = factoty.openSession();

        UserMapper mapper = sqlSession.getMapper(UserMapper.class);

        mapper.add(user);

        sqlSession.commit();

        sqlSession.close();
    }
}
