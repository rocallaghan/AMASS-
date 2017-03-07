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
	<div id="latAndLong">
		<h1 id="mapLatitude"></h1>
		<h1 id="mapLongitude"></h1>
	</div>
	
	<div id="map"></div>

	<br><br><br>
		<form action="MainPage.php">
			<input type="submit" value="Home"/>
		</form>
	</body>
	
	<script src="https://www.gstatic.com/firebasejs/3.7.0/firebase.js"></script>
	<script>
		// Initialize Firebase
		var config = {
			apiKey: "AIzaSyAqMwE4tGUKcAc4d0SnXNCG_Xex6kWI75A",
			authDomain: "test-f3317.firebaseapp.com",
			databaseURL: "https://test-f3317.firebaseio.com",
			storageBucket: "test-f3317.appspot.com",
			messagingSenderId: "354909114354"
			};
		firebase.initializeApp(config);
		

		var dbRef2 = firebase.database().ref('LatTest').child('x1');
		dbRef2.on('value', snap => mapLatitude.innerText = snap.val());
		var dbRef1 = firebase.database().ref('LongTest').child('y1');
		dbRef1.on('value', snap => mapLongitude.innerText = snap.val());
		
	</script>
	
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
</html>
