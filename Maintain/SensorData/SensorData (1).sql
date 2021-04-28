-- phpMyAdmin SQL Dump
-- version 4.6.6deb4+deb9u2
-- https://www.phpmyadmin.net/
--
-- 主機: localhost:3306
-- 產生時間： 2021 年 04 月 26 日 15:10
-- 伺服器版本: 10.1.48-MariaDB-0+deb9u1
-- PHP 版本： 7.0.33-0+deb9u10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 資料庫： `testc`
--

-- --------------------------------------------------------

--
-- 資料表結構 `SensorData`
--

CREATE TABLE `SensorData` (
  `id` int(6) UNSIGNED NOT NULL,
  `sensor` varchar(30) NOT NULL,
  `location` varchar(30) NOT NULL,
  `value1` varchar(10) DEFAULT NULL,
  `value2` varchar(10) DEFAULT NULL,
  `value3` varchar(10) DEFAULT NULL,
  `reading_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 資料表的匯出資料 `SensorData`
--

INSERT INTO `SensorData` (`id`, `sensor`, `location`, `value1`, `value2`, `value3`, `reading_time`) VALUES
(1, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:38:23'),
(2, 'esp8266-1', 'myroom', '29', '53', '0', '2021-04-18 10:38:54'),
(3, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:39:24'),
(4, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:39:54'),
(5, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:40:24'),
(6, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:40:54'),
(7, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:41:24'),
(8, 'esp8266-1', 'myroom', '26', '54', '0', '2021-04-18 10:41:54'),
(9, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:42:24'),
(10, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:42:54'),
(11, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:43:24'),
(12, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:43:54'),
(13, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:44:24'),
(14, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:44:54'),
(15, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:45:24'),
(16, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:45:54'),
(17, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:46:24'),
(18, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:46:54'),
(19, 'esp8266-1', 'myroom', '26', '54', '0', '2021-04-18 10:47:24'),
(20, 'esp8266-1', 'myroom', '26', '54', '0', '2021-04-26 06:21:31'),
(21, 'esp8266-1', 'myroom', '26', '54', '0', '2021-04-18 10:48:25'),
(22, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:48:55'),
(23, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:49:25'),
(24, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:49:55'),
(25, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:50:25'),
(26, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:50:56'),
(27, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:51:26'),
(28, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:51:56'),
(29, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:52:26'),
(30, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-18 10:52:56'),
(31, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(32, 'esp8266-1', 'myroom', '26', '54', '0', '2021-04-26 04:01:31'),
(33, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(34, 'esp8266-1', 'myroom', '26', '54', '0', '2021-04-26 04:01:31'),
(35, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(36, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(37, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(38, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(39, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(40, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(41, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(42, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(43, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(44, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(45, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(46, 'esp8266-1', 'myroom', '27', '53', '0', '2021-04-26 04:01:31'),
(47, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(48, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(49, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31'),
(50, 'esp8266-1', 'myroom', '26', '53', '0', '2021-04-26 04:01:31');

--
-- 已匯出資料表的索引
--

--
-- 資料表索引 `SensorData`
--
ALTER TABLE `SensorData`
  ADD PRIMARY KEY (`id`);

--
-- 在匯出的資料表使用 AUTO_INCREMENT
--

--
-- 使用資料表 AUTO_INCREMENT `SensorData`
--
ALTER TABLE `SensorData`
  MODIFY `id` int(6) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=701;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
