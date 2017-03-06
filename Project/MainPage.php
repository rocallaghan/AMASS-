<!doctype html>
<html lang="en">
	<head>
		<meta charset="utf-8"/>
		<title>Home</title>
		<link rel="stylesheet" href="main.css">
	</head>
	
	<body class="body">
		<header>
			<h1 class="PageTitle">
				<nav>
					<a href="MainPage.php">Automobile Management & Security System</a>
				</nav>
			</h1>
		</header>
		<br><br>
		<div>
			<h2>PICTURE GOES HERE</h2>		
		</div>
		<br><br><br><br><br><br>
		<div id="3columndiv">
			<div id="leftdiv">
				<h1 id="texttitle">Location of the car with Google Maps</h1>
				<h2>This page will show the location of your car with the use of Google Maps.</h2>
				<form action="map.php">
					<input type="submit" value="Maps"/>
				</form>
			</div>
			<div id="middiv">
				<h1 id="texttitle">Remote Shutdown</h1>
				<h2>This page will let you shut down the car remotely.</h2>
				<form action="shutdown.php">
					<input type="submit" value="Shutdown"/>
				</form>
			</div>
			<div id="rightdiv">
				<h1 id="texttitle">Previous Locations</h1>
				<h2>This page will show you all of the co ordinates of the previous locations of the car.</h2>
				<form action="locations.php">
					<input type="submit" value="Locations"/>
				</form>
			</div>
		</div>
	
	</body>
</html>