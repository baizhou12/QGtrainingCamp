package com.xieweixiang;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/Servlet")
public class Servlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            String username = request.getParameter("username");
            String password = request.getParameter("password");
            System.out.println(username);
            System.out.println(password);
            if (username != null && password != null && username.equals("qgstdio") && password.equals("qgstdio")) {
                response.setStatus(200);
            } else {
                response.setStatus(401);
            }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
//实在不知道问题出在哪里，接受后输出的参数一直是null，正常提交的话没有问题，但是使用ajax提交就一直是null