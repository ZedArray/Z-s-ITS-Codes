<%@ page import="java.security.*"%>
<%@ page import="java.math.BigInteger"%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="java.sql.*"%>

<%
    public String MD5(String input) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");

            md.update(input.getBytes(), 0, input.length());

            String hash = new BigInteger(1, md.digest()).toString(16);

            while (hash.length() < 32) {
                hash = "0" + hash;
            }

            return hash;
        } 
		catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    Connection conn = null;
    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        String url = "jdbc:mysql://localhost:3306/user_db";
        String username = "root";
        String password = "";
        conn = DriverManager.getConnection(url, username, password);
    } catch (Exception e) {
        e.printStackTrace();
    }

    if (conn == null) {
        out.println("Failed to make connection to the database.");
    } else {
        if (request.getParameter("submit") != null) {
            String name = request.getParameter("name");
            String email = request.getParameter("email");
            String password = MD5(request.getParameter("password"));
            String cpassword = MD5(request.getParameter("cpassword"));
            String user_type = request.getParameter("user_type");

            String selectQuery = "SELECT * FROM user_form WHERE email = ? AND password = ?";
            try {
                PreparedStatement preparedStatement = conn.prepareStatement(selectQuery);
                preparedStatement.setString(1, email);
                preparedStatement.setString(2, password);
                ResultSet resultSet = preparedStatement.executeQuery();

                if (resultSet.next()) {
                    out.println("User already exists!");
                } 
				else {
                    if (password.equals(cpassword)) {
                        String insertQuery = "INSERT INTO user_form(name, email, password, user_type) VALUES (?, ?, ?, ?)";
                        preparedStatement = conn.prepareStatement(insertQuery);
                        preparedStatement.setString(1, name);
                        preparedStatement.setString(2, email);
                        preparedStatement.setString(3, password);
                        preparedStatement.setString(4, user_type);
                        preparedStatement.executeUpdate();
                        response.sendRedirect("loginForm.jsp");
                    } 
					else {
                        out.println("Password not matched!");
                    }
                }
            } 
			catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
%>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>register form</title>

    <!-- custom css file link  -->
    <link rel="stylesheet" href="AdminStyle.css">
</head>
<body>
<div class="form-container">
    <form action="" method="post">
        <h3>register now</h3>
        <% if (out.getBufferSize() > 0) { %>
            <span class="error-msg"><%= out.toString() %></span>
        <% } %>
        <input type="text" name="name" required placeholder="enter your name">
        <input type="email" name="email" required placeholder="enter your email">
        <input type="password" name="password" required placeholder="enter your password">
        <input type="password" name="cpassword" required placeholder="confirm your password">
        <select name="user_type">
            <option value="user">user</option>
            <option value="admin">admin</option>
        </select>
        <input type="submit" name="submit" value="register now" class="form-btn">
        <p>already have an account? <a href="loginForm.jsp">login now</a></p>
    </form>
</div>
</body>
</html>
