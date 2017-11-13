import java.sql.*;

class testjdbc
{
	public static void main(String Args[]) throws Exception
	{
		String deiverName="com.mysql.jdbc.Driver";
		String url="jdbc:mysql://localhost/java";
		String userid="root";
		String password="";
		//load driver
		Class.forName(driverName).newInstance();
		System.out.println("driver load success");

		//create connection
		Connection con=DriverManager.getConnection(url,uid,pwd);

		//create statement
		Statement stmt=con.createStatement();

		//write query
		String sql="insert into student values('1','utsav','1234')";
		//
		stmt.Execute

	}
}