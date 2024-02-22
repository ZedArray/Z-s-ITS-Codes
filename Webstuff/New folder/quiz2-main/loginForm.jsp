<%@ page import="java.sql.*, java.io.*, javax.servlet.*, javax.servlet.http.*"%>
<%@ page import="java.util.*"%>

<%
    
    String path = request.getRealPath("/WEB-INF/config.jsp");
    pageContext.include(path);

    HttpSession session = request.getSession();

    if (request.getParameter("submit") != null) {
        String email = request.getParameter("email");
        String password = request.getParameter("password");

        String hashedPassword = MD5(password);

        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/user_db", "root", "");
            stmt = conn.createStatement();

            String selectQuery = "SELECT * FROM user_form WHERE email = '" + email + "' AND password = '" + hashedPassword + "'";
            rs = stmt.executeQuery(selectQuery);

            if (rs.next()) {
                String userType = rs.getString("user_type");

                if ("admin".equals(userType)) {
                    session.setAttribute("admin_name", rs.getString("name"));
                    response.sendRedirect("adminPage.jsp");
                } else if ("user".equals(userType)) {
                    session.setAttribute("user_name", rs.getString("name"));
                    response.sendRedirect("userPage.jsp");
                }
            } 
			else {
               
                out.println("<span class='error-msg'>Incorrect email or password!</span>");
            }
        } 
		catch (Exception e) {
            e.printStackTrace();
        } 
		finally {
            try { if (rs != null) rs.close(); } catch (Exception e) {}
            try { if (stmt != null) stmt.close(); } catch (Exception e) {}
            try { if (conn != null) conn.close(); } catch (Exception e) {}
        }
    }

    String MD5(String md5) {
        try {
            java.security.MessageDigest md = java.security.MessageDigest.getInstance("MD5");
            byte[] array = md.digest(md5.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : array) {
                sb.append(Integer.toHexString((b & 0xFF) | 0x100).substring(1, 3));
            }
            return sb.toString();
        } 
		catch (java.security.NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return null;
    }
%>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Form</title>

    <!-- Custom CSS file link -->
    <link rel="stylesheet" href="AdminStyle.css">
</head>
<body>

<div class="form-container">

    <form action="" method="post">
        <h3>Login Now</h3>
        <%
            if (request.getAttribute("error") != null) {
                out.println("<span class='error-msg'>" + request.getAttribute("error") + "</span>");
            }
        %>
        <input type="email" name="email" required placeholder="Enter your email">
        <input type="password" name="password" required placeholder="Enter your password">
        <input type="submit" name="submit" value="Login Now" class="form-btn">
        <p>Don't have an account? <a href="registerForm.jsp">Register now</a></p>
    </form>

</div>

</body>
</html>
