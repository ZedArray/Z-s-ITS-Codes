<%@ page import="java.io.*,java.util.*" %>
<%@ page import="javax.servlet.*" %>
<%@ page import="javax.servlet.http.*" %>

<%@ page session="false" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%
    HttpSession session = request.getSession(false);

    if (session == null || session.getAttribute("user_name") == null) {
        response.sendRedirect("loginForm.jsp");
    }
%>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>user page</title>

    <link rel="stylesheet" href="AdminStyle.css">
</head>
<body>

<div class="container">
    <div class="content">
        <h3>hi, <span>user</span></h3>
        <h1>welcome <span><%= session.getAttribute("user_name") %></span></h1>
        <p>this is a user page</p>
        <a href="loginForm.jsp" class="btn">login</a>
        <a href="registerForm.jsp" class="btn">register</a>
        <a href="logout.jsp" class="btn">logout</a>
    </div>
</div>

</body>
</html>
