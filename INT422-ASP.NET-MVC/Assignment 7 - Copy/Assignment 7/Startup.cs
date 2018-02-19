using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Assignment_7.Startup))]
namespace Assignment_7
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
