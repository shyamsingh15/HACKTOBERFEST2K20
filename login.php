<!DOCTYPE html>
<html>
<head>
<title> User And Registration Form</title> 
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script> 
<style>
body { 
  background: lightblue url("quiz4.gif") no-repeat fixed center; 
}
</style>

</head>
<body >
<br><h1 class="text-center text-success" ><u>Welcome To Quiz Test </u></h1><br><br>
 
        <div class="container" >
       
		<div class="row">
		<div class="col-md-6">
		<img src="quiz1.png" height="335"width="470">
		</div>
		    
			
		        <div class="col-md-3 ">
				<div class="card">
			
				
		 <div class="login-box">
		
				<h2 class="text-center text-success card-header"> Login Here</h2>
                  <form action="validation.php" method="post">
				  <div class="form-group">
				    <label>Username</label>
				     <input type="text" name="user" class="form-control" required/>
				 </div>
				      <div class="form-group">
         				  <label>Password</label>
		        		  <input type="password" name="password" class="form-control" required>
						  
				     </div>
					 <button type="submit" class="btn btn-primary">Login </button>

				  </form>		
                 </div>
			</div>	
			</div> 
				
				 
				  <div class="col-md-3 ">
				<div class="card">
			
				
		 <div class="login-box">
		
				<h2 class="text-center text-success card-header"> Singup Here</h2>
                  <form action="registration.php" method="post">
				  <div class="form-group">
				    <label>Username</label>
				     <input type="text" name="user" class="form-control" required/>
				 </div>
				      <div class="form-group">
         				  <label>Password</label>
		        		  <input type="password" name="password" class="form-control" required>
						  
				     </div>
					 <button type="submit" class="btn btn-primary">Sing Up </button>

				  </form>		
                 </div>
			</div>	
			</div> 
				 
		   </div>
		</div>   
	</div>	
 </body>
 </html>