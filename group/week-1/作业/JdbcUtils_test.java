package com.xieweixiang.jdbc;
import java.sql.*;

public class JdbcUtils_test {
    public static void main(String[] args) {
        Connection conn = null;
        try {
            conn = JDBC_Utils.getConnection();
            JDBC_Utils.beginTransaction(conn);

            String sql1 = "UPDATE ACCOUNT SET SALARY=2000 WHERE NAME='张三'";
            String sql2 = "UPDATE ACCOUNT SET SALARY=0 WHERE NAME='李四'";

            int rowsAffected1 = JDBC_Utils.executeUpdate(sql1);
            int rowsAffected2 = JDBC_Utils.executeUpdate(sql2);

            if (rowsAffected1 > 0 && rowsAffected2 > 0) {
                JDBC_Utils.commitTransaction(conn);
                System.out.println("事务提交成功");
            } else {
                conn.rollback();
                System.out.println("事务回滚");
            }
        } catch (SQLException e) {
            e.printStackTrace();
            try {
                if (conn != null) {
                    conn.rollback();
                }
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBC_Utils.closeResource(conn);
        }
    }
}
