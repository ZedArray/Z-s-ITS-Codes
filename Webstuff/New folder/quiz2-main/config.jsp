<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.io.*,java.util.*" %>

<!DOCTYPE html>
<html lang="en">
<head>
   <meta charset="UTF-8">
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>admin page</title>

   <link rel="stylesheet" href="AdminStyle.css">
</head>
<body>
   <div class="container">
      <div class="content">
         <h3>hi, <span>admin</span></h3>
         <h1>welcome <span><%= session.getAttribute("admin_name") %></span></h1>
         <p>this is an admin page</p>
         <a href="loginForm.jsp" class="btn">login</a>
         <a href="registerForm.jsp" class="btn">register</a>
         <a href="logout.jsp" class="btn">logout</a>
      </div>
   </div>
</body>
</html>
