<!DOCTYPE html>
<html lang="uk">
<head>
  <meta charset="UTF-8">
  <title>КіноКвитки Онлайн</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background: #f5f5f5;
      padding: 30px;
      text-align: center;
    }
    h1 {
      color: #222;
    }
    .movie-grid {
      display: flex;
      flex-wrap: wrap;
      justify-content: center;
      gap: 20px;
    }
    .movie-card {
      background: #fff;
      border-radius: 10px;
      box-shadow: 0 2px 8px rgba(0,0,0,0.1);
      width: 260px;
      text-align: left;
      overflow: hidden;
    }
    .movie-card img {
      width: 100%;
      height: 360px;
      object-fit: cover;
    }
    .movie-info {
      padding: 15px;
    }
    .movie-title {
      font-size: 18px;
      font-weight: bold;
    }
    .movie-desc {
      font-size: 14px;
      margin-top: 5px;
      color: #555;
    }
    .movie-card button {
      margin-top: 10px;
      background: #1976d2;
      color: white;
      padding: 10px;
      border: none;
      width: 100%;
      cursor: pointer;
      border-radius: 0 0 10px 10px;
      font-size: 16px;
    }
    .seats {
      display: grid;
      grid-template-columns: repeat(5, 60px);
      gap: 10px;
      justify-content: center;
      margin: 20px auto;
      max-width: 300px;
    }
    .seat {
      width: 50px;
      height: 50px;
      background: #ccc;
      border-radius: 6px;
      cursor: pointer;
      line-height: 50px;
      text-align: center;
    }
    .seat.selected {
      background: #4caf50;
      color: white;
    }
    select, button.confirm-btn {
      padding: 10px;
      margin: 10px;
      font-size: 16px;
    }
    .result {
      margin-top: 20px;
      font-size: 18px;
    }
    #bookingSection {
      margin-top: 40px;
    }
  </style>
</head>
<body>

  <h1>🎬 Онлайн сервіс купівлі квитків</h1>
  <div class="movie-grid" id="movies"></div>

  <div id="bookingSection" style="display:none;">
    <h2>Оберіть час та місце</h2>
    <div>
      <label for="time">Час:</label>
      <select id="time">
        <option disabled selected>-- Виберіть час --</option>
        <option>12:00</option>
        <option>15:00</option>
        <option>18:00</option>
        <option>21:00</option>
      </select>
    </div>

    <h3>Оберіть місце:</h3>
    <div class="seats" id="seats"></div>

    <button class="confirm-btn" onclick="confirmBooking()">Підтвердити замовлення</button>
    <div class="result" id="result"></div>
  </div>

  <script>
    const movieList = [
      {
        title: "Оппенгеймер",
        description: "Біографічна драма про створення атомної бомби. Режисер Крістофер Нолан.",
        genre: "Драма, Історичний",
        duration: "180 хв",
        poster: "https://m.media-amazon.com/images/M/MV5BN2EyZjM3YTct.jpg"
      },
      {
        title: "Вартові Галактики 3",
        description: "Команда Вартових знову об’єднується для нової міжгалактичної пригоди.",
        genre: "Фантастика, Пригоди",
        duration: "150 хв",
        poster: "https://m.media-amazon.com/images/M/MV5BMjMxMjM0Nzg3Nl5BMl5BanBnXkFtZTgwMTU5MjE2NzM@._V1_.jpg"
      },
      {
        title: "Барбі",
        description: "Життя в Рожевому Світі змінюється, коли Барбі вирушає у реальний світ.",
        genre: "Комедія, Фентезі",
        duration: "110 хв",
        poster: "https://m.media-amazon.com/images/M/MV5BYTg0NjM0MTAt.jpg"
      },
      {
        title: "Інтерстеллар",
        description: "Астронавти подорожують через кротову нору в пошуках нової планети.",
        genre: "Фантастика, Драма",
        duration: "169 хв",
        poster: "https://m.media-amazon.com/images/M/MV5BMjIxMjgxNzM4MF5BMl5BanBnXkFtZTgwNzUxNzE3MjE@._V1_FMjpg_UX1000_.jpg"
      },
      {
        title: "Дюна: Частина друга",
        description: "Пол Атрейдес веде боротьбу за виживання на пустельній планеті.",
        genre: "Епік, Фантастика",
        duration: "165 хв",
        poster: "https://m.media-amazon.com/images/M/MV5BZjMxN2EzZDct.jpg"
      },
      {
        title: "Коко",
        description: "Мігель потрапляє у світ мертвих, щоб знайти історію своєї родини.",
        genre: "Анімація, Пригоди",
        duration: "105 хв",
        poster: "https://m.media-amazon.com/images/M/MV5BMjExN2U1M2Et.jpg"
      }
    ];

    const moviesDiv = document.getElementById("movies");
    const seatsDiv = document.getElementById("seats");
    let selectedMovie = null;
    let selectedSeat = null;

    movieList.forEach((movie, index) => {
      const card = document.createElement("div");
      card.className = "movie-card";
      card.innerHTML = `
        <img src="${movie.poster}" alt="${movie.title}">
        <div class="movie-info">
          <div class="movie-title">${movie.title}</div>
          <div class="movie-desc">${movie.description}</div>
          <div class="movie-desc"><b>Жанр:</b> ${movie.genre}</div>
          <div class="movie-desc"><b>Тривалість:</b> ${movie.duration}</div>
        </div>
        <button onclick="selectMovie(${index})">Обрати</button>
      `;
      moviesDiv.appendChild(card);
    });

    function selectMovie(index) {
      selectedMovie = movieList[index];
      document.getElementById("bookingSection").style.display = "block";
      window.scrollTo(0, document.body.scrollHeight);
      generateSeats();
    }

    function generateSeats() {
      seatsDiv.innerHTML = "";
      selectedSeat = null;
      for (let i = 1; i <= 20; i++) {
        const seat = document.createElement("div");
        seat.className = "seat";
        seat.innerText = i;
        seat.addEventListener("click", () => {
          document.querySelectorAll(".seat").forEach(s => s.classList.remove('selected'));
          seat.classList.add('selected');
          selectedSeat = i;
        });
        seatsDiv.appendChild(seat);
      }
    }

    function confirmBooking() {
      const time = document.getElementById("time").value;
      if (!selectedMovie || !time || !selectedSeat) {
        alert("Будь ласка, оберіть фільм, час і місце.");
        return;
      }

      document.getElementById("result").innerHTML = `
        ✅ <b>Замовлення підтверджено!</b><br>
        🎬 Фільм: <b>${selectedMovie.title}</b><br>
        🕒 Час: <b>${time}</b><br>
        💺 Місце: <b>${selectedSeat}</b>
      `;
    }
  </script>

</body>
</html>https://www.onlinegdb.com/#tab-stdin
