<!doctype html>
<html lang="en">
	<head>
		<meta charset="utf-8"/>
		<title>Google Maps Location</title>
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
		<h1>Google Maps Location</h1>
	<div id="map"></div>
	<script>
		function initMap() 
		{
			var uluru = {lat: 51.884, lng: -8.534};//need to get co ords from database
			var map = new google.maps.Map(document.getElementById('map'), {
		 	 zoom: 4,
		 	 center: uluru
			});
			var marker = new google.maps.Marker({
		 	 position: uluru,
		 	 map: map
			});
		}
	</script>
	<script async defer src="https://maps.googleapis.com/maps/api/js?key=AIzaSyB2Yq5o_z-vUr_-U4P9dafWecinJ1YMp3E&callback=initMap">
	</script>
	<br><br><br>
		<form action="Mainpage.php">
			<input type="submit" value="Home"/>
		</form>
	</body>
</html>
