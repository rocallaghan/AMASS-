<!doctype html>
<html lang="en">
	<head>
		<meta charset="utf-8"/>
		<title>Locations</title>
		<link rel="stylesheet" href="main.css">
	</head>
	
	<body class="body">
		<header>
			<h1 class="PageTitle">
				<nav>
					<a href="MainPage.html">Automobile Management & Security System</a>
				</nav>
			</h1>
		</header>
		<br>
		<h1>List of previous locations</h1>
		<br><br><br>
		<div id = locationList>
			<table>
				<thead>
					<tr>
						<td><b>X Loc</b></td>
						<td><b>Y loc</b></td>
					</tr>
				</thead>
				<tbody id="table_body">
				</tbody>
			</table>
		</div>
		<form action="MainPage.php">
			<input type="submit" value="Home"/>
		</form>
	</body>
	
	<script src="https://www.gstatic.com/firebasejs/3.7.0/firebase.js"></script>
	<script>
	// Initialize Firebase
	var config = 
	{
		apiKey: "AIzaSyAqMwE4tGUKcAc4d0SnXNCG_Xex6kWI75A",
		authDomain: "test-f3317.firebaseapp.com",
		databaseURL: "https://test-f3317.firebaseio.com",
		storageBucket: "test-f3317.appspot.com",
		messagingSenderId: "354909114354"
	};
    firebase.initializeApp(config);
	</script>
	<script src="https://code.jquery.com/jquery-3.1.0.js"></script>
	<script>
	  // Initialize Firebase
	var config = 
	{
		apiKey: "AIzaSyAqMwE4tGUKcAc4d0SnXNCG_Xex6kWI75A",
		authDomain: "test-f3317.firebaseapp.com",
		databaseURL: "https://test-f3317.firebaseio.com",
		storageBucket: "test-f3317.appspot.com",
		messagingSenderId: "354909114354"
	};
	firebase.initializeApp(config);
	</script>
	<script src="https://code.jquery.com/jquery-3.1.0.js"></script>
	<script>
	$(document).ready(function()
	{
		var rootRef = firebase.database().ref().child("Coords");
		rootRef.on("child_added", snap => 
		{
			var x = snap.child("x").val();
			var y = snap.child("y").val();
			$("#table_body").append("<tr><td>" + x +"</td><td>" + y + "</td></tr>");
		});
	});
	</script>
</html>
