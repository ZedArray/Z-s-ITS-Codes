<%@ page import="java.io.*, javax.servlet.*, javax.servlet.http.*"%>

<%
    String path = request.getRealPath("/WEB-INF/config.jsp");
    pageContext.include(path);

    HttpSession session = request.getSession();

    session.invalidate();

    response.sendRedirect("loginForm.jsp");
%>
