package com.xieweixiang.web;

import com.alibaba.fastjson.JSON;
import com.xieweixiang.pojo.User;
import com.xieweixiang.service.userService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/loginServlet")
public class loginServlet extends HttpServlet {
    private userService service = new userService();

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        BufferedReader br = request.getReader();

        String params = br.readLine();

        User user1 = JSON.parseObject(params, User.class);

        User user2 = service.selectUserServlet(user1.getUsername(), user1.getPassword());

        if (user2 != null) {
            response.getWriter().write("success");
        } else {
            response.getWriter().write("failure");
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
