package com.xieweixiang.jdbc;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

public class JDBC_Utils {
//    使用数据库连接池获取连接
        public static Connection getConnection() throws Exception {
            Properties prop=new Properties();
           prop.load(new FileInputStream("jdbc-demo/src/druid.properties"));
            DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
            Connection conn = dataSource.getConnection();
            return conn;
        }

//释放conn资源
    public static void closeResource(Connection conn) {
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

//    释放rs,stmt资源
        public static void closeResource(Statement stmt, ResultSet rs) {
            try {
                if (rs != null) {
                    rs.close();
                }
                if (stmt != null) {
                    stmt.close();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

//        执行更新操作
        public static int executeUpdate(String sql) throws Exception {
            Connection conn = null;
            Statement stmt = null;
            try {
                conn = getConnection();
                stmt = conn.createStatement();
                return stmt.executeUpdate(sql);
            } catch (SQLException e) {
                e.printStackTrace();
                return -1;//错误返回-1
            } finally {
                closeResource(stmt, null);
            }
        }

//        开启事物
    public static void beginTransaction(Connection conn) throws SQLException {
        conn.setAutoCommit(false);
    }

//    提交事物
    public static void commitTransaction(Connection conn) throws SQLException {
        conn.commit();
        conn.setAutoCommit(true);
    }
    }


