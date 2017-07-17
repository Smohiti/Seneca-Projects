-- phpMyAdmin SQL Dump
-- version 4.6.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 28, 2017 at 09:15 AM
-- Server version: 5.7.14
-- PHP Version: 7.0.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `lab4`
--

-- --------------------------------------------------------

--
-- Table structure for table `fsossregister`
--

CREATE TABLE `fsossregister` (
  `ID` int(3) NOT NULL,
  `First_Name` varchar(20) NOT NULL,
  `Last_Name` varchar(20) NOT NULL,
  `Sex` varchar(1) NOT NULL,
  `Size` varchar(8) NOT NULL,
  `Multiple_Yes` tinyint(1) DEFAULT NULL,
  `Multiple_No` tinyint(1) DEFAULT NULL,
  `Amount` int(3) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `fsossregister`
--

INSERT INTO `fsossregister` (`ID`, `First_Name`, `Last_Name`, `Sex`, `Size`, `Multiple_Yes`, `Multiple_No`, `Amount`) VALUES
(3, 'Justin', 'Trudeau', 'M', 'Large', 1, 0, 6),
(2, 'Barack', 'Obama', 'M', 'Medium', 0, 0, 3),
(1, 'Donald', 'Trump', 'F', 'Small', 0, 1, 1),
(4, 'Hillary', 'Clinton', 'F', 'Small', 1, 0, 8);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `fsossregister`
--
ALTER TABLE `fsossregister`
  ADD UNIQUE KEY `ID_2` (`ID`),
  ADD KEY `ID` (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `fsossregister`
--
ALTER TABLE `fsossregister`
  MODIFY `ID` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
