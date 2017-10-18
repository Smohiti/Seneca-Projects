using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_2.Controllers
{
    public class HomeController : Controller
    {
        // Reference to the data manager
        private Manager m = new Manager();

        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your superb App description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your awesome contact page.";

            return View();
        }
    }
}